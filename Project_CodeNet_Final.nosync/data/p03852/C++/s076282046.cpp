#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
using namespace std;
using ll = long long;
int main(){
    char c;
    cin >> c;
    if(c == 'a' || c== 'i' || c == 'u' || c == 'e' || c == 'o')
        cout << "vowel" << endl;
    else
    {
        cout << "consonant" << endl;
    }
    
    return 0;
}