#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n=1,t;
    while(cin>>n,n){
        int num=0,count=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            cin >>t;
            count++;
            v.push_back(t);
            num+=t;
        }
        num -= *max_element(v.begin(),v.end());
        num -= *min_element(v.begin(),v.end());
        int ans=(double)num/(count-2);
        cout<<ans<<endl; 
    }
}