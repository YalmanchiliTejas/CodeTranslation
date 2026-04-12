#include <bits/stdc++.h>
using namespace std;
int main(void){
    long n,x,m,ans=0;
    cin >> n >> x >> m;
    if(x==0){
        cout << 0 << endl;
        return 0;
    } 
    vector<long> k,s(m);
    map<long,long> mp;
    long cur = x,d=0,e=0;
    k.push_back(cur);
    mp[cur] = 1;
    for(int i=2;i<=m;i++){
        cur = (cur*cur)%m;
        k.push_back(cur);
        if(1<=mp[cur]){
            d = mp[cur];
            e = i;
            break;
        }  
        mp[cur] = i;
    }
    long fsum = 0,cirsum=0,resum=0;
    for(int i=0;i<d-1;i++) fsum += k[i];
    for(int i=d-1;i<e-1;i++) cirsum += k[i];
    for(int i=0;i<=(n-d)%(e-d);i++) resum += k[d-1+i];
    cout << fsum + (n-d)/(e-d)*cirsum + resum << endl;
}