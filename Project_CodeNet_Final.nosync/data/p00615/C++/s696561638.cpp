#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m,n||m){
        vector<int>v;
        for(int i=0;i<n+m;i++){
            int a;cin>>a;
            v.push_back(a);
        }
        v.push_back(0);

        sort(v.begin(),v.end());

        int ma=0;
        for(int i=0;i<v.size()-1;i++)ma=max(ma,v[i+1]-v[i]);

        cout<<ma<<endl;
    }
    return 0;
}