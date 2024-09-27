#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

int findparent(int u,vector<int>&parent)
	{
	    if(u==parent[u])
	    return u;
	    
	    return parent[u]=findparent(parent[u],parent);
	}
	
	void unionbyrank(int u,int v,vector<int>&parent,vector <int>& rank)
	{
	    int pu=findparent(u,parent);
	    int pv=findparent(v,parent);
	    
	    if(rank[pu]>rank[pv])
	    {
	        parent[pu]=pv;
	    }
	    if(rank[pv]>rank[pu])
	    {
	        parent[pv]=pu;
	    }
	    if(rank[pu]==rank[pv])
	    {
	        parent[pu]=pv;
	        rank[pu]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    
    vector<int>rank(V,0);
    vector<int>parent(V);
    for(int i=0;i<V;i++)
    parent[i]=i;
    
    vector<pair<int,pair<int,int>>>temp;
	for(int i=0;i<V;i++)
	{
	    for(int j=0;j<adj[i].size();j++)
	    {
	        //u->v
	        int wgt=adj[i][j][1];
	        int v=adj[i][j][0];
	        int u=i;
	        temp.push_back({wgt,{u,v}});
	    }
	    
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
        int cost=0;
        while(!pq.empty())
        {
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            
            int pu=findparent(u,parent);
            int pv=findparent(v,parent);
            if(pu!=pv)
            {
                unionbyrank(u,v,parent,rank);
                cost+=pq.top().first;
            }
            pq.pop();
        }
        return cost;
    }


int main()
{
    cout<<"kruskal";


    return 0;
}