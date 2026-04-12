#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define se second
using namespace std;

const ll N = 2e3 + 7;
ll mod = 1e9 + 7;
map<int , int> mp , mp1 , pm , pm1;
ll n , m , ans , x , y , a , b ,  mx , mn  ;
long long cnt;
int sum;
string s , s1 , s2;
vector<int>v;
set<char>st;
char z , u;
  ll arr[N][N];
int main(){
    cin >> s;
    for( int i = 0 ;i < s.size();i ++ )
        st.insert(s[i]);
    if( st.size() != 1 )
        cout << "Yes";
    else
        cout << "No";
    }

