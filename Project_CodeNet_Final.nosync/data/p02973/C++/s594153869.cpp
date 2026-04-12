#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    multiset<int> s;

    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        auto it = s.lower_bound(t);
        if(it!=s.begin()){
            s.erase(--it);
        }
        s.insert(t);
    }
    cout<<(int)s.size();
}


