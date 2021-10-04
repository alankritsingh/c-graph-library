//Created By: alan_2109
#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<int> adj[100005];
    bool vis[100005];
    int n,m;
    Graph(int nodes,int edges){
        n=nodes;
        m=edges;
        for(int i=0;i<=nodes;i++)
        {
            vis[i]=false;
        }

    }
    void initialize()
    {
        for(int i=0;i<=n;i++)
        {
            vis[i]=false;
        }
    }
    void addEdge(int a,int b,bool dir)
    {
        adj[a].push_back(b);
        if(!dir)
        {
            adj[b].push_back(a);
        }
    }
    void dfs(int s,vector<long long int> &res)
    {
        vis[s]=true;
        res.push_back(s);
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i]])
            {
                dfs(adj[s][i],res);
            }
        }
    }
    void bfs(int s,vector<long long int> &res)
    {
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(!q.empty())
        {
            res.push_back(q.front());
            for(int i=0;i<adj[q.front()].size();i++)
            {
                if(!vis[adj[q.front()][i]])
                {
                    vis[adj[q.front()][i]]=true;
                    q.push(adj[q.front()][i]);
                }
            }
            q.pop();
        }
    }
    void findLevel(int s,vector<long long int> &level)
    {
        for(int i=1;i<=n;i++)
        {
            level.push_back(-1);
        }
        level[s-1]=0;
        vis[s]=true;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            for(int i=0;i<adj[p].size();i++)
            {
                if(!vis[adj[p][i]])
                {
                    level[adj[p][i]-1]=level[p-1]+1;
                    vis[adj[p][i]]=true;
                    q.push(adj[p][i]);
                }
            }
        }
    }
    int connected_components()
    {
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                ans++;
                queue<int> q;
                q.push(j);
                vis[j]=true;
                while(!q.empty())
                {
                    for(int i=0;i<adj[q.front()].size();i++)
                    {
                        if(!vis[adj[q.front()][i]])
                        {
                            vis[adj[q.front()][i]]=true;
                            q.push(adj[q.front()][i]);
                        }
                    }
                    q.pop();
                }
            }
        }
        return ans;
    }
};

class Weighted_Graph{
public:
    vector<pair<int,int>> adj[100005];
    bool vis[100005];
    int n,m;
    Weighted_Graph(int nodes,int edges){
        n=nodes;
        m=edges;
        for(int i=0;i<=nodes;i++)
        {
            vis[i]=false;
        }

    }
    void initialize()
    {
        for(int i=0;i<=n;i++)
        {
            vis[i]=false;
        }
    }
    void addEdge(int a,int b,int c,bool dir)
    {
        adj[a].push_back({b,c});
        if(!dir)
        {
            adj[b].push_back({a,c});
        }
    }
    void dfs(int s,vector<long long int> &res)
    {
        vis[s]=true;
        res.push_back(s);
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i].first])
            {
                dfs(adj[s][i].first,res);
            }
        }
    }
    void bfs(int s,vector<long long int> &res)
    {
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(!q.empty())
        {
            res.push_back(q.front());
            for(int i=0;i<adj[q.front()].size();i++)
            {
                if(!vis[adj[q.front()][i].first])
                {
                    vis[adj[q.front()][i].first]=true;
                    q.push(adj[q.front()][i].first);
                }
            }
            q.pop();
        }
    }
    void dijkstra(int s,vector<long long int> &res)
    {
        for(int i=1;i<=n;i++)
        {
            res.push_back(-1);
        }
        res[s-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++)
            {
                if(!vis[adj[node][i].first])
                {

                    if(res[adj[node][i].first-1]!=-1)
                    {

                        res[adj[node][i].first-1]=min(res[adj[node][i].first-1],(long long int)(dist+adj[node][i].second));

                    }
                    else
                    {

                        res[adj[node][i].first-1]=dist+adj[node][i].second;
                    }
                    pq.push({res[adj[node][i].first-1],adj[node][i].first});
                }
            }
            while(!pq.empty()&&vis[pq.top().second])
            {
                pq.pop();
            }
        }
    }
};

#endif

