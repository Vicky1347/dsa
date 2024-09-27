#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include <sstream> // For stringstream to split input line
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;

void printmtx(const vector<vector<int> > &gph)
{
    for (const auto &x : gph)
    {
        for (const auto &y : x)
            cout << y << " ";
        cout << endl;
    }
}

class Topological
{
    public:
    stack<int>s;
    void DFSREC(vector<vector<int> > gph,int source, vector<bool> &visited)
    {
        visited[source] = true;

        for (auto x : gph[source])
        {
            if (visited[x] == false)
            {
                DFSREC(gph, x, visited); 
            }
            
        }
        s.push(source);
        
    }

    // cheaking that undirected graph is circular or not
    void toposort(vector<vector<int> > &gph)
    {
        int n = gph.size();
        vector<bool> visited(n,false);
        vector<int>ans;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                DFSREC(gph,i,visited);
                    
            }
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        
    }
};

class circular
{
public:
    bool DFSREC(vector<vector<int> > &gph, int source, int parent, vector<bool> &visited)
    {
        visited[source] = true;

        for (auto x : gph[source])
        {
            if (visited[x] == false)
            {
                if (DFSREC(gph, x, source, visited))
                    return true;

                
            }
            else if (x != parent)return true;
        }
        return false;
    }

    // cheaking that undirected graph is circular or not
    bool iscircularDFS(vector<vector<int> > &gph)
    {
        int n = gph.size();
        vector<bool> visited(n,false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (DFSREC(gph, i, -1, visited))
                    return true;
            }
        }
        return false;
    }

    //---------using BFS---------------------------//
    bool iscircularBFS(vector<vector<int> > & gph)
    {
        int n=gph.size();
        vector<bool> visited(n,false);
        queue<pair<int,int> >q;
        q.push( {0,-1} );
        visited[0]=true;
        while(!q.empty())
        {
            int vertex = q.front().first;
            int parent = q.front().second;
            //int curr=q.front();
            //cout<<curr<<" ";
            //visited[curr]==false;
            q.pop();
            for(auto neighour: gph[vertex])
            {
                if(visited[neighour]==false)
                {
                    q.push( {neighour, vertex} );
                    visited[neighour]=true;
                }
                else if(neighour!=parent )
                return true;
            }
        }
        return false;

    }


};

int main()
{
    // Graph
    // cout << "Enter number of nodes in graph: ";
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after entering `n`

    vector<vector<int> > gph(n);

    // Input each line of vertices
    for (int i = 0; i < n; i++)
    {
        // cout << "Enter vertices connected to node " << i <<": ";
        string line;
        getline(cin, line); // Read the whole line of input

        stringstream ss(line); // Use stringstream to split the input line
        int k;
        while (ss >> k)
        { // Extract integers from the line
            gph[i].push_back(k);
        }
    }

    // Print the graph matrix
    //printmtx(gph);
    //cout << boolalpha << circular().iscircularDFS(gph);
    //cout<<boolalpha<<circular().iscircularBFS(gph);
    Topological().toposort(gph);
    return 0;
}
