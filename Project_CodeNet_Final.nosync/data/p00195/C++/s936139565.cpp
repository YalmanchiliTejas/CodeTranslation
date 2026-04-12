#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b, a||b){
        int max = a + b;
        char ans = 'A';
        range(i,1,5){
            cin >> a >> b;
            if(max < a + b){
                ans = 'A' + i;
                max = a + b;
            }
        }
        cout << ans << ' ' << max << endl;
    }
}