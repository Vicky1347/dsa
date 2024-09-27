#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //pq<weight,node,parent>
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int>>>> pq;
        int cost=0;
        vector<int>visited(V,0);
        vector<int>parent(V,0);
        pq.push({0,{0,-1}});
        while(!pq.empty())
        {
            int weight=pq.top().first;
            int node=pq.top().second.first;
            int par=pq.top().second.second;
            pq.pop();
            if(visited[node]==0)
            {
                for(int i=0;i<adj[node].size();i++)
                {
                    pq.push({adj[node][i][1],{adj[node][i][0],node}});
                }
                visited[node]=1;
                parent[node]=par;
                cost+=weight;
            }
        }
        return cost;
    }

int main()
{

    return 0;
}