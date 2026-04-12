#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;


string s;
int ind;

int number(){
    int ret = s[ind] - '0';
    ind++;
    return ret;
}

int term(){
    int ret = number();
    while(1){
        if(s[ind] == '*'){
            ind++;
            ret *= number();
        }else{
            break;
        }
    }
    return ret;
}

int expression(){
    int ret = term();
    while(1){
        if(s[ind] == '+'){
            ind++;
            ret += term();
        }else{
            break;
        }
    }
    return ret;
}
int f(){
    int ret = number();
    while(1){
        if(s[ind] == '+'){
            ind++;
            ret += number();
        }else if(s[ind] == '*'){
            ind++;
            ret *= number();
        }else{
            break;
        }
    }
    return ret;
}
int main(void) {
    int i,j;
    cin >> s;
    int x;
    cin >> x;
    ind = 0;
    int ans1 = expression();
    ind = 0;
    int ans2 = f();
    if(ans1 == x && ans2 == x){
        cout << "U" << endl;
    }else if(ans1 == x){
        cout << "M" << endl;
    }else if(ans2 == x){
        cout << "L" << endl;
    }else{
        cout << "I" << endl;
    }

}

