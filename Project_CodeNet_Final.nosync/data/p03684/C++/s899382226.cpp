#include <bits/stdc++.h>

using namespace std;
typedef long long I64;
const I64 NMAX = 200000;
const I64 MOD  = 1000000007;

multiset<I64> ST;
multiset<I64>::iterator it;

bool cmp( pair<pair<I64,I64>, I64> A, pair<pair<I64,I64>, I64> B ) {
    return (A.first.second < B.first.second || (A.first.second==B.first.second && A.first.first < B.first.first));
}

I64 N = 0, Ans = 0;
vector< pair<pair<I64,I64>, I64> > v;
vector< pair<I64, pair<I64,I64>> > edg;

I64 tt[NMAX+2], gr[NMAX+2];

I64 ROOT(I64 nod) {
    if( nod == tt[nod] ) return nod;
    return tt[nod] = ROOT(tt[nod]);
}

void UNION(  I64 x, I64 y ) {
    x = ROOT(x);
    y = ROOT(y);
    if  ( gr[x] > gr[y] ) {
        gr[x] += gr[y];
        tt[y] = x;
    }
    else {
        gr[y] += gr[x];
        tt[x] = y;
    }
}

int main() {
    cin >> N;
    for( I64 i = 1;  i <= N;  ++i ) {
        tt[i] = i;
        gr[i] = 1;
        I64 x,y;
        cin >> x >> y;
        v.push_back( {{x,y}, i} );
    }
    sort( v.begin(), v.end() );
    for( I64 i = 1;  i < (I64)v.size();  ++i ) {
        I64 lg = v[i].first.first - v[i-1].first.first;
        edg.push_back( {lg, {v[i].second, v[i-1].second}} );
    }
    sort( v.begin(), v.end(), cmp );
    for( I64 i = 1;  i < (I64)v.size();  ++i ) {
        I64 lg = v[i].first.second - v[i-1].first.second;
        edg.push_back( {lg, {v[i].second, v[i-1].second}} );
    }

    sort( edg.begin(), edg.end() );
    for( auto pp : edg ) {
        I64 x = pp.second.first;
        I64 y = pp.second.second;
        I64 lg = pp.first;
        if( ROOT(x) != ROOT(y) ) {
            Ans += lg;
            UNION(x,y);
        }
    }

    cout << Ans << '\n';
    return 0;
}
