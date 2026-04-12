#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define SQ(a) (a) * (a)
#define deb(x) cout << #x << " = " << x << '\n'
#define deb2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
 
 
int main(int argc, char const *argv[])
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n>=30){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}