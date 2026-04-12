
#include<bits/stdc++.h>
#define int long long
#define double long double
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define set set<int>
#define u_set unordered_set<int>
#define pb push_back
#define mp make_pair
#define M 1000000007
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define endl "\n"
#define BRISK ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
signed main()
{
    BRISK;
    string s;
    cin>>s;
    int one=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A')one++;
    }

    if(one==0 || one==3)cout<<"No";
    else cout<<"Yes";
}