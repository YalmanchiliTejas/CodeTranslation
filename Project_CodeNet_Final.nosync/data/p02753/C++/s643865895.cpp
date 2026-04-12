#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll unsigned long long
#define md 1000000007
#define pb push_back
#define ff first
#define ss second
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,start,end) for(ll i=start;i<end;i++) 
using namespace std;
using namespace __gnu_pbds;
typedef priority_queue<int, vector<int>, greater<int> > min_pq;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }


int main(){
    fio();
    string s;
    cin>>s;
    if(s[0]==s[1] and s[0]==s[2])
    cout<<"No";
    else
        cout<<"Yes";
    return 0;
}