#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main(){

    int n;
    cin >> n;
    string s[60];
    vector<char> output;
    int min = 1000;
    int min_index;

    for(int i=0; i<n; i++){
        cin >> s[i];
        int st_size = s[i].size();
        if(min > st_size){
            min = st_size;
            min_index = i;
        }
    }

    int roop = n-1;

    for(int k=0; k<s[min_index].size(); k++){
        bool flag = true;
        while(roop >= 0){
            if(roop == min_index) {
                roop--;
                continue;
            }

            int bas = s[roop].find(s[min_index][k]);
            //他の文字列のいずれのときでも見つからないとき(例えば入力で言えばb,d)
            if(bas == -1) {flag = false;}
            else{
                //見つかったとき
                s[roop].replace(bas, 1, "-");
            }

            //次の文字列へ
            roop--;
        }

        if(flag) {
            output.push_back(s[min_index][k]);

        }

        //再度設定
        roop = n - 1;
    }


    if(output.size() == 0){
    }else{
        vector<char>::iterator ite;
        sort(output.begin(), output.end());
        for(ite = output.begin(); ite != output.end(); ite++) cout << *ite;
    }

    cout << endl;

}