#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<cctype>
#include<complex>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<numeric>
using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 1e+8
#define EPS 1e-8
#define PB push_back
#define fi first
#define se second
#define ll long long 
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
typedef pair<int,int> Pii;
typedef vector <int> vi;
bool check(int a, string str){
    if(a%15 == 0)
        return str == "FizzBuzz";
    if(a%5 == 0)
        return str == "Buzz";
    if(a%3 == 0)
        return str == "Fizz";
    return a == atoi(str.c_str());
}
 
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m), n){
        set<int> player;
        
        rep(i, n){
            player.insert(i);
        }

        set<int>::iterator itr = player.begin();
        
        rep(i, m){
            string str;
            int len;
            do{
                cin >> str;
                len = str.size();
                if(str[len-1] == '\n'){
                    str[len-1] = '\0';
                    --len;
                }
            }while(len==0);
            if(player.size() > 1){
                if(check(i+1, str)){
                    ++itr;
                }
                else{
                    player.erase(itr++);
                }
                if(itr == player.end()){
                    itr = player.begin();
                }
            }
        }
 
        int roop = 0;
        for(itr=player.begin(); itr!=player.end(); ++itr, ++roop){
            printf("%d%c", *itr+1, roop+1==player.size() ? '\n' : ' ');
        }
    }
    return 0;
}