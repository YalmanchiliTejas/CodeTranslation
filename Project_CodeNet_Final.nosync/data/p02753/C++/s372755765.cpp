#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define px(x) cout << x << endl
#define pfi(x) printf("%d\n", x)
#define pfs(x) printf("%s\n", x)
#define sfi(x) scanf("%d", &x)
#define sfs(x) scanf("%s", x)


int main(int argc, char const *argv[])
{          
   string s;
   cin >> s;

   int ca = 0;
   int cb = 0;

   for(int i=0; i<s.length(); i++){
    if(s[i] == 'A'){
        ca += 1;
    }else if(s[i] == 'B'){
        cb += 1;
    }
   }

   if(ca == 2 && cb == 1){
    cout << "Yes";
   }else if(ca == 1 && cb ==2){
    cout << "Yes";
   }else{
    cout << "No";
   }






    return 0;
}