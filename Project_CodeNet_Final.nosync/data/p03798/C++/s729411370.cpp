#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(int i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(int i = (a); i > (b); --i)
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)
//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
static const int NIL = -1;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector>	DVector;
int n;

//配列の表示
void printArray(int array[], int n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

char rev_sw(char a){
    char res;
    if(a == 'S')    res = 'W';
    else    res = 'S';
    
    return res;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    char s[n];
    rep(i, n)   cin >> s[i];
    
    bool judge = false;
    //1, 2を（羊、羊）（羊、狼）（狼、羊）（狼、狼）の4パターンで進める。
    char tmp[n];
    rep(p, 4){
        switch(p){
            case 0:
            tmp[0] = 'S';
            tmp[1] = 'S';
            break;
            
            case 1:
            tmp[0] = 'S';
            tmp[1] = 'W';
            break;
            
            case 2:
            tmp[0] = 'W';
            tmp[1] = 'S';
            break;
            
            case 3:
            tmp[0] = 'W';
            tmp[1] = 'W';
            break;
        }
        
        //答え合わせ
        char ans1 = 'a';
        if(s[0] == 'o'){
                if(tmp[0] == 'S'){
                    ans1 = tmp[1];
                }else if(tmp[0] == 'W'){
                    ans1 = rev_sw(tmp[1]);
                }
        }else if(s[0] == 'x'){
                if(tmp[0] == 'S'){
                    ans1 = rev_sw(tmp[1]);
                }else if(tmp[0] == 'W'){
                    ans1 = tmp[1];
                }
        }
        
        //添え字1 ~ n - 2(2 ~ n - 1)を見てn - 1(n)まで決める。
        FOR(i, 1, n - 1){
            if(s[i] == 'o'){
                if(tmp[i] == 'S'){
                    tmp[i + 1] = tmp[i - 1];
                }else if(tmp[i] == 'W'){
                    tmp[i + 1] = rev_sw(tmp[i - 1]);
                }
            }else if(s[i] == 'x'){
                if(tmp[i] == 'S'){
                    tmp[i + 1] = rev_sw(tmp[i - 1]);
                }else if(tmp[i] == 'W'){
                    tmp[i + 1] = tmp[i - 1];
                }
            }
        }
        
        char ans2 = 'a';
        if(s[n - 1] == 'o'){
                if(tmp[n - 1] == 'S'){
                    ans2 = tmp[n - 2];
                }else if(tmp[n - 1] == 'W'){
                    ans2 = rev_sw(tmp[n - 2]);
                }
        }else if(s[n - 1] == 'x'){
                if(tmp[n - 1] == 'S'){
                    ans2 = rev_sw(tmp[n - 2]);
                }else if(tmp[n - 1] == 'W'){
                    ans2 = tmp[n - 2];
                }
        }
        
        
        //cout << ans << " "  << tmp[n - 1] << endl;
        if(ans1 == tmp[n - 1] && ans2 == tmp[0]){
            judge = true;
            break;
        }
    }
    
    if(judge){
        rep(i, n)   cout << tmp[i];
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}