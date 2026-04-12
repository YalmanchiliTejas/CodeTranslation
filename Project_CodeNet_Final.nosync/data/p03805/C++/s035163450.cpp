#include <bits/stdc++.h>
using namespace std;
template <class ForwardIterator, class T>
  void iota (ForwardIterator first, ForwardIterator last, T val)
{
  while (first!=last) {
    *first = val;
    ++first;
    ++val;
  }
}
int g[11][11]={0};
int main()
{
    int n,m,x,y,res=0;
    cin>>n>>m;
    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x-1][y-1] = g[y-1][x-1] = 1;
    }
    do{
        bool flag = true;
        if(p[0])break;//視点が1の時はbreak
        for(int i=1;i<n;i++){
            if(!g[p[i-1]][p[i]])flag=false;//つながってない
        }
        if(flag)res++;
    }while(next_permutation(p.begin(),p.end()));
    cout<<res<<endl;
    return 0;
}