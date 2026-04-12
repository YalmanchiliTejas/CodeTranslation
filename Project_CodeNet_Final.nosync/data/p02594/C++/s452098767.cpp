#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define newline cout<<"\n"
#define deb(x) cout<<#x<<" "<<x<<endl;

template<typename... T>
void read(T&... args){
    ((cin>>args), ...);
}

template<typename... T>
void write(T... args){
    ((cout<<args<<" "), ...);
}

void printarr(vector<int> &v){
    for(int x: v){
        cout<<x<<" ";
    }
    newline;
}

const int MOD = 1e9+7;
const int nax = 1e7+7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int x; cin>>x;
    if(x>=30){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    
    return 0;
}