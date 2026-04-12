#include<iostream>
using namespace std;main(){string r, k="hijklmnopyu";while(cin>>r,r!="#"){bool f,s;int ans=0;f = ~(k.find(r[0]));for(char c:r){s=~(k.find(c));if(f^s)ans++;f=s;}cout<<ans<<endl;}}