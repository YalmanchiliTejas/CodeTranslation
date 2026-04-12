#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>


const int MOD = 1000000007;
int main(){

   string s;
   cin >> s;
    bool f = false;
    char a = s[0];
   for(int i=0;i < 3;i++){
       if(s[0] != s[i]){
           f = true;
       }
       
   }
   if(f){
       cout << "Yes" << endl;

   }else{
       cout << "No" << endl;
   }
   
    
    
    
    return 0;
}