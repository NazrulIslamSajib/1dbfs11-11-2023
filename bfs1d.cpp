#include<bits/stdc++.h>
using namespace std;
int level[10010];
int main()
{
     memset(level,-1,10010);
     int n,m,i,s;
     cin>>n>>m>>s;
     vector<int>adj[n+123];
     vector<int>path(n+123,-1);
     for(i=1;i<=m;i++)
     {
         int a,b;
         cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
     }
     queue<int>q;
     q.push(s);
     level[s]=0;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(auto v:adj[u])
         {
             if(level[v]==-1)
             {
                 path[v]=u;
                 level[v]=level[u]+1;
                 q.push(v);
             }
         }
     }
     vector<int>ans;
     int p;
     cin>>p;
     ans.push_back(p);
     while(path[p]!=-1)
     {
         ans.push_back(path[p]);
         p=path[p];

     }
     ///for path
     for(auto x:ans)
     {
         cout<<x<<" ";
     }
     /*
     cout<<endl;
     for(i=1;i<=n;i++)
     {
         cout<<i<<"   level :"<<level[i]<<endl;
     }
     */
    // cout<<level[6]<<endl;

}
/*
7 6 1
1 2
1 3
2 4
2 5
3 6
3 7
7
*/

