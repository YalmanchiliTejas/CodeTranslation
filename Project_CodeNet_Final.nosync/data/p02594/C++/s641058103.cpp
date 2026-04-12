#include <bits/stdc++.h>
#include <chrono>

using namespace std;
//using namespace std::chrono;

#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

void print(vi v){
    cout<<"Contents of vector:\n";
    for(auto x : v) cout<<x<<" ";
    cout<<endl<<endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); //cout.tie(nullptr);
    //ifstream cin("lmio_1991_3e1_seka_01.in"); ofstream cout("lmio_1991_3e1_seka_01.out");///cia failai

    //int T; cin>>T;
    int T = 1;

    for(int it = 1; it<=T; it++){
        int n; cin>>n;
        if(n >= 30) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}
