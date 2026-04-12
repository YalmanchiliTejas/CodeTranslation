// abc.058 C - Dubious Document

// Sn（すべて）の中の文字を用いて、文字列を作る。複数できる場合は辞書順で最小のもの

#include <bits/stdc++.h>
using namespace std;

int main( void ) {

    int n;
    cin >> n;
    vector<int> res( 26, 55 );

    for( int i = 0; i < n; i++ ) {
        string s;
        cin >> s;

        vector<int> AB( 26, 0 );

        for( int j = 0; j < s.length(); j++ ) {
            char c = s.at( j );
            AB.at( c - 'a' )++;
        }
        // ABとresの少ない方を保存する
        for( int j = 0; j < 26; j++ ) {
            res.at( j ) = min( AB.at( j ), res.at( j ) );
        }
    }

    string ans;

    for( int i = 0; i < 26; i++ ){
        ans +=string(res.at(i), i + 'a');
    }
    cout << ans << endl;

    return 0;
}
