#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD=1e9+7;
const double PI=3.14159265359;






int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    list<int> li;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(i%2){
            li.push_back(x);
        }
        else{
            li.push_front(x);
        }
    }
    if(n%2){
        for(auto it=li.rbegin(); it!=li.rend(); it++){
            cout<<*it<<" ";
        }
        return 0;
    }
    
    for(int i:li){
        cout<<i<<" ";
    }
    
    
    
    
    return 0;
}