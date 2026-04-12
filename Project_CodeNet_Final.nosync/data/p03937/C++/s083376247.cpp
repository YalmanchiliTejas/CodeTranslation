// unolight {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
// }}}

const int MAX_N = 100005;
int n, m;
char a[10][10];
void input() {
    RI(n, m);
    REP(i, n) 
        REP(j, m) {
            char c;
            while((c=getchar()) == '\n');
            a[i][j] = c;
        }
}

void solve() {
    queue<pair<int,int>> q;
    q.push({0,0});
    a[0][0] = '.';
    while (!q.empty())
    {
        int i=q.front().first, j=q.front().second;
        q.pop();
        if(a[i+1][j] == '#') {
            a[i+1][j] = '.';
            q.push({i+1, j});
        } else if(a[i][j+1] == '#') {
            a[i][j+1] = '.';
            q.push({i, j+1});
        }
    }

    #ifdef DEBUG
    REP(i, n) {
        REP(j, m)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    #endif

    REP(i, n) REP(j, m) if(a[i][j] == '#') {
        printf("Impossible\n");
        return;
    }
    printf("Possible\n");
}

int main( int argc, char *argv[] ) {
    input();
    solve();
    return 0;
}