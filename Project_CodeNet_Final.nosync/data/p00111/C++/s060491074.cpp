#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
#define repr(i ,n) for(int i=n;i>(int)(n);--i)
#define rep1(i ,n) for(int i=1;i<=(int)(n);++i)
#define ALL(a) a.begin(), a.end()
#define RSORT(a) sort(ALL(a),greater<>())
#define SORT(a) sort(ALL(a))
#define bit_check(bit, i) ((bit>>(i)) & 1)
#define PRINT(x) cout << (x) << endl;
#define ENDL cout << endl;
using namespace std;
typedef long long int i64;
typedef unsigned long long u64;
template<class T> using V = vector<T>;
using VI = V<int>;
const int INF = 2e9;
const i64 MOD = 1e9 + 7;

template <class T> inline bool chmin(T& a, T b){if(a>b){a=b; return true;} return false;}
template <class T> inline bool chmax(T& a, T b){if(a<b){a=b; return true;} return false;}
struct Init_On{
    Init_On(){
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(16);
    }
};

signed main(){
    string s;
    while( getline(cin , s)){
        string enc;
        stringstream ss;
        for(int i = 0 ; i < s.size() ; ++i){
            ss.str("");
            if(s[i] == ' ') enc += "11010";
            else if( s[i] == '.') enc += "11011";
            else if( s[i] == ',') enc += "11100";
            else if( s[i] == '-') enc += "11101";
            else if( s[i] == '\'') enc += "11110";
            else if( s[i] == '?') enc += "11111";
            else { ss << bitset<5>(s[i]-'A'); enc += ss.str(); }
        }
        string slv;
        int j = 0;
        for( ; j < enc.size() ; ++j){
            for(int k = 3; k <= 8 ; ++k) {
                string tmp = enc.substr(j , k);
                if( k == 3){
                    if     (tmp == "101") { slv += ' '; j+=2; break; }
                    else if(tmp == "110") { slv += 'E'; j+=2; break; }
                    else if(tmp == "111") { slv += 'P'; j+=2; break; }
                    else continue;
                } else if (k == 4){
                    if     (tmp == "0101") { slv += 'C'; j+=3; break; }
                    else if(tmp == "0001") { slv += 'D'; j+=3; break; }
                    else if(tmp == "0111") { slv += 'I'; j+=3; break; }
                    else if(tmp == "0110") { slv += 'K'; j+=3; break; }
                    else if(tmp == "1000") { slv += 'R'; j+=3; break; }
                    else continue;
                } else if ( k == 5){
                    if     (tmp == "01001") { slv += 'F'; j+=4; break; }
                    else if(tmp == "00100") { slv += 'L'; j+=4; break; }
                    else if(tmp == "00101") { slv += 'O'; j+=4; break; }
                    else if(tmp == "00110") { slv += 'S'; j+=4; break; }
                    else if(tmp == "00111") { slv += 'T'; j+=4; break; }
                    else continue;
                } else if ( k == 6 ){
                    if     (tmp == "000000") { slv += '\''; j+=5; break; }
                    else if(tmp == "000001") { slv += '?'; j+=5; break; }
                    else if(tmp == "000011") { slv += ','; j+=5; break; }
                    else if(tmp == "010001") { slv += '.'; j+=5; break; }
                    else if(tmp == "100101") { slv += 'A'; j+=5; break; }
                    else if(tmp == "010000") { slv += 'H'; j+=5; break; }
                    else if(tmp == "000010") { slv += 'W'; j+=5; break; }
                    else continue;
                } else if ( k == 8){
                    if     (tmp == "10010001") { slv += '-'; j+=7; break; }
                    else if(tmp == "10011010") { slv += 'B'; j+=7; break; }
                    else if(tmp == "10011000") { slv += 'J'; j+=7; break; }
                    else if(tmp == "10011011") { slv += 'G'; j+=7; break; }
                    else if(tmp == "10011001") { slv += 'M'; j+=7; break; }
                    else if(tmp == "10011110") { slv += 'N'; j+=7; break; }
                    else if(tmp == "10011111") { slv += 'Q'; j+=7; break; }
                    else if(tmp == "10011100") { slv += 'U'; j+=7; break; }
                    else if(tmp == "10011101") { slv += 'V'; j+=7; break; }
                    else if(tmp == "10010010") { slv += 'X'; j+=7; break; }
                    else if(tmp == "10010011") { slv += 'Y'; j+=7; break; }
                    else if(tmp == "10010000") { slv += 'Z'; j+=7; break; }
                    else continue;
                }
            }
        }
        cout << slv << endl;
    }
}
