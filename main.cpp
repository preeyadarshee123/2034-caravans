//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf 1<<30
#define eps 0.000000001
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // let's fuck the bfs and dfs
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int a,b;
    f(i,m)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int s,f,r;
    cin>>s>>f>>r;
    queue<int> q;
    vector<int> vis(n+1,0);
    vector<int> dis(n+1,-1);
    q.push(s);
    vis[s]=1;
    dis[s]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i:adj[temp])
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dis[i]=dis[temp]+1;
                q.push(i);
            }
        }
    }
    vector<int>dist(n+1,-1);
    q.empty();
    vis.assign(n+1,0);
    q.push(r);
    vis[r]=1;
    dist[r]=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i:adj[temp])
        {
            if(vis[i]==0)
            {
                dist[i]=dist[temp]+1;
                vis[i]=1;
                q.push(i);
            }
        }
    }
    vector<int>dis1(n+1,-1);
    q.empty();
    vis.assign(n+1,0);
    q.push(f);
    dis1[f]=0;
    vis[f]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i:adj[temp])
        {
            if(vis[i]==0)
            {
                dis1[i]=dis1[temp]+1;
                vis[i]=1;
                q.push(i);
            }
        }
    }
    map<int,int>ma;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]+dis1[i]==dis[f])
        {
            auto itr=ma.find(dis[i]);
            if(itr==ma.end())
            {
                ma.insert(mp(dis[i],dist[i]));
            }
            else
            {
                itr->second=max(itr->second,dist[i]);
            }
        }
    }
    auto itr=ma.begin();
    int mini=inf;
    while(itr!=ma.end())
    {
        mini=min(mini,itr->second);
        itr++;
    }
    cout<<mini<<endl;
}
