#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    int counter=0;
    counter+=x/(y+z);
    printf("%d\n",counter);
}