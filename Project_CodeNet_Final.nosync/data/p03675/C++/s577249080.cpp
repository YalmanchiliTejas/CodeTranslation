#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;


int n, a[200005];
int b[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i =0; i<n; ++i)
        cin>>a[i];
    int l = 0, r = n-1;
    int act = 0;
    for(int i = n-1; i>=0;i--){
        if(act==0){
            b[l]=a[i];
            ++l;
        }
        else{
            b[r]=a[i];
            --r;
        }
        act^=1;
    }
    for(int i =0; i<n; ++i){
        if(i)
            cout<<" ";
        cout<<b[i];
    }
    cout<<"\n";
    return 0;
}