/*
क्षमाशील हो रिपु-समक्ष
तुम हुये विनत जितना ही
दुष्ट कौरवों ने तुमको
कायर समझा उतना ही।
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int                 long long int
#define ull                 unsigned int
#define ld                  long double
#define pb                  push_back
#define ff                  first
#define ss                  second
#define S(arr)              sort(arr.begin(),arr.end());
#define all(p)              p.begin(), p.end()
#define RS(arr)             sort(arr.rbegin(),arr.rend());
#define R(arr)              reverse(arr.begin(),arr.end());
#define pii                 pair <int, int>
#define vpi                 vector <pii>
#define vi                  vector <int>
#define vld                 vector <ld>
#define vvi                 vector <vector <int>>
#define vs                  vector <string>
#define si                  set <int>
#define spi                 set <pii>
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mii                 map <int, int>
#define mci                 map<char, int>
#define mpi                 map <pii, int>
#define T                   int tcf;cin>>tcf;while(tcf--)
#define que_max(t)          priority_queue <t>
#define que_min(t)          priority_queue <t, vector<t>, greater<t>>
#define endl                "\n"
#define dba(a, l, r)        for(auto x:a)cout<<x<<" ";cout<<endl;
#define db1(x)              cout << #x " = " << x << endl;
#define db2(x,y)            cout << #x " = " << x << " " << #y " = " << y << endl;
#define db3(x,y,z)          cout << #x " = " << x << " " << #y " = " << y << " " << #z " = " << z << endl;
#define db4(x,y,z,w)        cout << #x " = " << x << " " << #y " = " << y << " " << #z " = " << z << " " << #w " = " << w << endl;
#define db5(x,y,z,w,v)      cout << #x " = " << x << " " << #y " = " << y << " " << #z " = " << z << " " << #w " = " << w << " " << #v " = " << v << endl;
#define db6(x,y,z,w,v,a)    db3(a, y, x)db3(w, v, a)
#define p2d(v)              for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)              for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppi(v)              for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;  
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//  // *( hsh.find_by_order(k) ) kth smallest, from 0
//  // hsh.order_of_key(k) num of ele str less than k
//  // change less to less_equal for multiset pbds
 
void read(int n=10){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<setprecision(n)<<fixed;
//    #ifndef ONLINE_JUDGE
  //       freopen("input.txt",  "r",  stdin);
    //     freopen("output.txt", "w", stdout);
   // #endif
}
 
int M = 1e9 + 7;
int M1 = 998244353;
#define qqq 4000005
#define pi 3.14159265358979323851



int32_t main(){
    read();
    string str;
    cin>>str;
    mii freq;
    for(auto a:str)
        freq[a]++;
    if(freq.size()==1){
        cout<<"No";
    }else
        cout<<"Yes";
}  