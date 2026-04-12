#include <bits/stdc++.h>
using namespace std;
/**
*   @Author: MeGaaaaaaaaaa
*   @InitTime: Mon Sep 09 17:35:29 2019
*   @Idea: 
*
*
*
*
* Happy Solving :)
**/
const int N=2e5+7;
int pos[N];
int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin)
//    freopen("out","w",stdout)
#endif
     int n;
     cin>>n;
     vector<pair<int,int> >v;
     for(int i=1;i<=n;i++){
     	int a;
     	cin>>a;
     	v.push_back(make_pair(a,i));
     }
     sort(v.rbegin(),v.rend());
     for(int i=0;i<n;i++){
     	pos[v[i].second]=i+1;
     }
     for(int i=1;i<=n;i++){
     	if(pos[i]<=(n/2)){
     	    cout<<v[(int)n/2].first<<endl;
     	}else{
     	   cout<<v[(int)n/2 -1].first<<endl;
     	}
     }





}
