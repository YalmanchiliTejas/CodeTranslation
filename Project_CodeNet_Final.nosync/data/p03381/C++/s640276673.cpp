#include<bits/stdc++.h>
using namespace std;
int a,s,d[200002],f,g,h,j,k,l,i,n,m;
multiset<int> s1,s2;
vector<int> v;
main(){
    cin>>n;
    v.push_back(-1);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        v.push_back(a);
        d[i]=a;//cout<<d[i]<<"^";
    }

    sort(v.begin(),v.end());
    l=v[n/2];k=v[n/2+1];
    for(i=0;i<n;i++){
        if(d[i]<=l) printf("%d\n",k); else printf("%d\n",l);
    }
}
