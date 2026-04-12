#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
//#include <vector>
#include <string>
//#include <unordered_map>
//typedef long long LL;
//typedef long double LD;
using namespace std;

//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    string s;
    int a=0;
    int b=0;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A'){
            a++;
        }else{
            b++;
        }
    }
    if(a>0 && b>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}