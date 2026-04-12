#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define pb push_back
#define vv vector<ll>
#define MAX 105000
#define rr pow(10,9)+7
#define fr(i,x) for(int i=0;i<x;i++)
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    
    if(a.first == b.first) return a.second<b.second;
    return (a.first < b.first); 
}
ll ar[MAX];
void divisor(){
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i; j <= MAX;j+=i)
        {
            ar[j]++;
            
        }
        
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll f = pow(10,9)+7;
    ll n,x,c = 0,y,m;
    cin >>n;
    vector<ll>a,b;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x%f);
    }
    b.push_back(a[n-1]);
    for (ll i = 1; i < n; i++)
    {
        b.push_back(b[i-1]+a[n-i-1]);
    }
    //cout << endl;
    for (ll i = 0; i < n-1; i++)
    {
        c += (a[i] % f)*(b[n-i-2]%f);
        c = c%f;
    }
    cout << c << endl;
    
    
}