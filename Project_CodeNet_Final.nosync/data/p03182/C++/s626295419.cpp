#include <iostream>
#include <vector>
using namespace std;
class gh{
public:
  long long int maxval;
  long long int lazy;
};

long long int n;

gh* segTree;

long long int max(long long int a, long long int b)
{
  if(a > b) return a;
  else return b;
}

void buildsegtree(long long int n)
{
   for (long long int i = 0; i < 4*n + 1; ++i)
   {
     segTree[i].maxval = 0;
     segTree[i].lazy = 0;
   }
}

long long int max_query(long long int qs, long long int qe, long long int si, long long int ei, long long int ind)
{
   if(qs > ei || qe < si) return 0;

   segTree[ind].maxval += segTree[ind].lazy;
   if(2*ind + 1 < 4*n+1)  segTree[2*ind+1].lazy += segTree[ind].lazy;
   if(2*ind + 2 < 4*n+1) segTree[2*ind+2].lazy += segTree[ind].lazy;
   segTree[ind].lazy = 0;

   if(qs <= si && ei <= qe)
   {
      return segTree[ind].maxval;
   }

   long long int a = max_query(qs, qe, si, ((si + ei)>>1), (ind<<1)+1);
   long long int b = max_query(qs, qe, ((si + ei)>>1) + 1, ei, (ind<<1)+2);

   return max(a, b);
}


void lazy_prop(long long int qs, long long int qe, long long int si, long long int ei, long long int ind, long long int val)
{
  
  segTree[ind].maxval += segTree[ind].lazy;
   if(2*ind + 1 < 4*n+1)  segTree[2*ind+1].lazy += segTree[ind].lazy;
   if(2*ind + 2 < 4*n+1) segTree[2*ind+2].lazy += segTree[ind].lazy;
   segTree[ind].lazy = 0;

  if(qs > ei || qe < si) return ;

  
   
   if(qs <= si && ei <= qe)
   {
      segTree[ind].maxval += val;
      if(2*ind + 1 < 4*n+1)  segTree[2*ind+1].lazy += val;
      if(2*ind + 2 < 4*n+1) segTree[2*ind+2].lazy += val;
      return;
   }

   lazy_prop(qs, qe, si, ((si + ei)>>1), (ind<<1)+1, val);
   lazy_prop(qs, qe, ((si + ei)>>1) + 1, ei, (ind<<1)+2, val);

   segTree[ind].maxval = max(segTree[2*ind+1].maxval, segTree[2*ind+2].maxval);
}


int main()
{
  long long int  m;
  cin >> n >> m;
  vector<pair<long long int, long long int> > vec[n];
  for (long long int i = 0; i < m; ++i)
  {
    long long int a, b, c;
    cin >> a >> b >> c;
    a -= 1;
    b -= 1;
    vec[b].push_back(pair<long long int, long long int>(a, c));
  }


  long long int arr1[n];

  segTree = new gh[ ((n<<1)<<1) + 1];
  buildsegtree(n);



  for (long long int i = 0; i < n; ++i)
  {
     long long int p = 0;

     if(i-1 >= 0) p = max(p, max_query(0, i-1, 0, n-1, 0));
     lazy_prop(i, i, 0, n-1, 0, p);

     for (long long int j = 0; j < vec[i].size(); ++j)
     {
        lazy_prop(vec[i][j].first, i, 0, n-1, 0, vec[i][j].second);
     }
  }



  cout << max(0, max_query(0, n-1, 0, n-1, 0));

  



  return 0;
}