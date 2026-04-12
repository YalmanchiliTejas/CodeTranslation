#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb(a) push_back(a)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int,int>
#define all(vec) (vec.begin()),(vec.end())
#define ll long long
#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x;
#define bit(n) (1<<(n))

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;i++)
#define FORVEC(i, v) for(int i = 0;i < sz(v);i++)

vector<int> x,s;
int finds(int key,int imin,int imax){
    if (imax < imin) {
        return -1;
    } else {
        int imid = imin + (imax - imin) / 2;
        if (s[imid] > key) {
            return finds(key, imin, imid - 1);
        } else if (s[imid] < key) {
            return finds(key, imid + 1, imax);
        } else {
            return imid;
        }
    }
}

int main(){
    int n;

    int buf;
    cin>>n;
    REP(i,n){
        cin>>buf;
        x.pb(buf);
    }
    copy(x.begin(), x.end(), back_inserter(s) );
    sort(all(s));
    int c=n/2;
    REP(i,n){
        if(finds(x[i],0,n-1)>=c){
            cout<<s[c-1]<<endl;
        }else{
            cout<<s[c]<<endl;
        }
    }
    return 0;
}
