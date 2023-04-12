#include<bits/stdc++.h>
using namespace std;
const long long int inf = -1e18;
const int N =2505;
int n,m;
long long int dist[N];
vector<pair<int,int>> adj[N];
bool visited[N];
void dijkstra();
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)dist[i]=inf;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    dist[1]=0;
    dijkstra();
    cout<<dist[n];
    return 0;
}
void dijkstra()
{
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        pair<int,int>head=pq.top();
        pq.pop();
        int f=head.first;
        int s=head.second;
        if(visited[s]==true)continue;
        visited[s]=true;
        for(auto j:adj[s])
        {
            if(dist[j.second]<dist[s]+j.first)
            {
                dist[j.second]=dist[s]+j.first;
                pq.push({dist[j.second],j.second});
            }
        }
    }
}
