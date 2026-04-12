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
    int N;
    cin>>N;
    vi H(N);
    rep(i,N) {
        cin>>H[i];
    }
    int answer=0;
    rep(i,N) {
        bool counter=true;
        for(int j=0; j<i; j++) {
            if(H[i]<H[j]) {
                counter=false;
            }
        }
        if(counter) answer++;
    }
    cout<<answer<<endl;
}