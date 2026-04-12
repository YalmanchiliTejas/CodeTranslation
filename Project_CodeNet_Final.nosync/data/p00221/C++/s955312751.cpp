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
#include<algorithm>
#include<stdlib.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m, n||m){
        string s;
        vector<int> p;
        vector<int>::iterator it;
        range(i,1,n+1){
            p.push_back(i);
        }
        range(i,1,m+1){
            cin >> s;
            if(p.size() == 1) continue;
            //テ」ツ?セテ」ツ?ィテ」ツつ?」ツ?淌」ツ??
            if(i % 3 == 0 && i % 5 == 0){
                if(s == "FizzBuzz"){
                    p.push_back(p.front());
                }
            }else if(i % 3 == 0){
                if(s == "Fizz"){
                    p.push_back(p.front());
                }
            }else if(i % 5 == 0){
                if(s == "Buzz"){
                    p.push_back(p.front());
                }
            }else{
                char num[10];
                for(int j = s.size(); j >= 0; j--){
                    num[j] = s[j];
                }
                if(i == atoi(num)){
                    p.push_back(p.front());
                }
            }
            p.erase(p.begin());
        }
        sort(p.begin(), p.end());
        for(it = p.begin(); it != p.end(); it++){
            if(it != p.begin()) cout << ' ';
            cout << *it;
        }
        cout << endl;
    }
}