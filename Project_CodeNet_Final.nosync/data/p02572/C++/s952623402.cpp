#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    long long int num=10e8+7;
    int t;
    while(cin>>t){
        vector<long long> v;
        while(t--){
            long long tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        long long sum=0;
        vector<long long> pre;
        long long rec=0;
        for(int i=1;i<v.size();i++){
            rec+=v[i];
        }
        for(int i=1;i<v.size();i++){
            pre.push_back(rec);
            rec-=v[i];
        }
        for(int i=0;i<v.size()-1;i++){
            long long tmp=(v[i]%num)*(pre[i]%num);
            tmp%=num;
            sum+=tmp;
        }
        sum=sum%num;
        cout<<sum<<endl;
    }   
    
    return 0;
}