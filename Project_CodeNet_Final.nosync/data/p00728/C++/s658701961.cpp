#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
int main(void){
    int n,ans=0;
    while(cin>>n,n){
        vi s(n);
        rep(i,n) cin>>s[i];
        sort(all(s));
        cout<<floor(accumulate(s.begin()+1,s.end()-1,0)/(n-2))<<endl;
    }
}