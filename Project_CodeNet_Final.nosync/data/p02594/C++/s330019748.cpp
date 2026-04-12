#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define ford(b,a) for(int i=b;i>=a;i--)
typedef pair<int, int> pi;
#define PI 3.14159265359
#define vi vector<int>
long long mod=1000000007;
//int count=INT_MAX;
 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    //cin>>testcases;
    //cout<<t;
    //scanf("%d",&t);
    while(testcases--){  
        int t;
        cin>>t;
        if(t>=30){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }                                                                                          
    
    return 0;
}