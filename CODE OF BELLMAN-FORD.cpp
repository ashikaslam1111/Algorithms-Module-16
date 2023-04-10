#include<bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u,v,w;
};
int n,m;
vector<edge>edg;
const int infinity=1e9;
const int N=1000;
int dist[N];
void bellMan_ford(int src);
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({u,v,w});
    }
    for(int i=0; i<N; i++)dist[i]=infinity;
    int src=1;
    dist[src]=0;
    bellMan_ford(src);
    for(int i=1; i<=n; i++)cout<<src<<" to "<<i<<" is "<<dist[i]<<endl;
    return 0;
}
void bellMan_ford(int src)
{
    for(int i=1; i<n; i++)
    {
        for(auto j:edg)
        {
            if(dist[j.v]>dist[j.u]+j.w)
                dist[j.v]=dist[j.u]+j.w;
        }
    }
}
