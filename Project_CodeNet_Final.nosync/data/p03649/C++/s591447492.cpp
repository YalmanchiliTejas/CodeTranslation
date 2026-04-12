#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a{};
    for(int i=0;i<n;i++){
        ll j;
        cin>>j;
        a.push_back(j);
    }
    bool flag=true;
    ll count=0;
    while(flag){
        flag=false;
        for(int i=0;i<n;i++){
            if(a.at(i)>=n){
                count+=a.at(i)/n;
                for(int j=0;j<n;j++){
                    if(j!=i){
                        a.at(j)+=a.at(i)/n;
                    }
                }
                a.at(i)=a.at(i)%n;
                flag=true;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
