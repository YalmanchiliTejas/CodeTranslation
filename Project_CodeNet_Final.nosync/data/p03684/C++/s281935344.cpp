#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
const int N=1e5+5;
const int INF=1e9+5;

int n;

struct edge{

  int v;
  int c;


};

vector <edge> nb[N];

priority_queue <pair <int,int> > pq;

long long mst=0;

struct point{

  int x;
  int y;
  int ind;

}p[N];

int cost[N];


int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}


bool point_sortx(point a,point b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

bool point_sorty(point a,point b)
{
    if(a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}

int dist[N];
bool vis[N];

void Calc_MST()
{
    int i;
    int v,d;

    for(i=1;i<=n;i++)
        dist[i]=INF;

    pq.push(make_pair(0,1));

    while(!pq.empty())
    {
        while(vis[pq.top().second])
        {
            pq.pop();
            if(pq.empty())
                break;
        }

        if(pq.empty())
            break;

        v=pq.top().second;

        d=-pq.top().first;

        mst+=d;

        vis[v]=true;
        pq.pop();

        for(i=0;i<nb[v].size();i++)
        {
            if(nb[v][i].c<dist[nb[v][i].v])
            {
                dist[nb[v][i].v]=nb[v][i].c;

                pq.push(make_pair(-nb[v][i].c,nb[v][i].v));
            }
        }


    }



}

int main()
{
   int i,j;
   edge temp;

   cin>>n;

   for(i=1;i<=n;i++)
   {
       scanf("%d%d",&p[i].x,&p[i].y);

       p[i].ind=i;

       cost[i]=INF;
   }



   sort(p+1,p+n+1,point_sortx);

   temp.v=p[2].ind;
   temp.c=p[2].x-p[1].x;

   nb[p[1].ind].push_back(temp);
   for(i=2;i<n;i++)
   {
       temp.v=p[i-1].ind;
       temp.c=p[i].x-p[i-1].x;

       nb[p[i].ind].push_back(temp);

       temp.v=p[i+1].ind;
       temp.c=p[i+1].x-p[i].x;

       nb[p[i].ind].push_back(temp);
   }

   temp.v=p[n-1].ind;
   temp.c=p[n].x-p[n-1].x;

   nb[p[n].ind].push_back(temp);




   sort(p+1,p+n+1,point_sorty);

   temp.v=p[2].ind;
   temp.c=p[2].y-p[1].y;

   nb[p[1].ind].push_back(temp);
   for(i=2;i<n;i++)
   {
       temp.v=p[i-1].ind;
       temp.c=p[i].y-p[i-1].y;

       nb[p[i].ind].push_back(temp);

       temp.v=p[i+1].ind;
       temp.c=p[i+1].y-p[i].y;

       nb[p[i].ind].push_back(temp);
   }

   temp.v=p[n-1].ind;
   temp.c=p[n].y-p[n-1].y;

   nb[p[n].ind].push_back(temp);

  /* for(i=1;i<=n;i++)
   {
       for(j=0;j<nb[i].size();j++)
        cout<<nb[i][j].v<<" - "<<nb[i][j].c<<"  ";

       cout<<endl;
   }*/

   Calc_MST();


   cout<<mst<<endl;

   return 0;
}
