#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    int N;
    string s;
    cin >> N;
    cin >> s;


    // 0, 1 番目の組み合わせは 4 通りしかないので全探索
    string ans;
    string allComb[4] = { "SS", "SW", "WS", "WW" };
    bool isConsistent = false;
    for( auto ini: allComb ){
        ans = ini;
        bool isSheep;
        if( ini[1] == 'S' ) isSheep = true;
        if( ini[1] == 'W' ) isSheep = false;
        // i-1, i 番目の動物から i+1 番目の動物を決める
        for( int i = 1; i < N; ++i ){
            if( s[i] == 'o' ){
                if( isSheep ){
                    if( ans[i-1] == 'S') ans += 'S';
                    else                 ans += 'W';
                }else{
                    if( ans[i-1] == 'S' ) ans += 'W';
                    else                  ans += 'S';
                }
            }else if( s[i] == 'x' ){
                if( isSheep ){
                    if( ans[i-1] == 'S') ans += 'W';
                    else                 ans += 'S';
                }else{
                    if( ans[i-1] == 'S') ans += 'S';
                    else                 ans += 'W';
                }
            }
            if( ans.back() == 'S' ) isSheep = true;
            else                    isSheep = false;
        }
        // ans に対して s[0] の条件式を判定
        if( ans.front() == ans.back() ){
            ans.pop_back();
            bool isOK = false;
            if( s[0] == 'o' ){
                if( ans[0] == 'S' ){
                    if( ans[1] == ans.back() ) isOK = true;
                }else{
                    if( ans[1] != ans.back() ) isOK = true;
                }
            }else if( s[0] == 'x' ){
                if( ans[0] == 'S' ){
                    if( ans[1] != ans.back() ) isOK = true;
                }else{
                    if( ans[1] == ans.back() ) isOK = true;
                }
            }
            if( isOK ){
                isConsistent = true;
                break;
            }
        }
    }

    if( isConsistent ) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}