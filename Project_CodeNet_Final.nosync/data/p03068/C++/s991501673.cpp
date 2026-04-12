#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
    
    int n,k;
    string s;
    cin >> n >> s >> k;
    char a = s[k-1];
    for (int i=0;i<n;i++){
        if(s[i] != a){
            cout << "*";
        }else{
            cout << s[i];
        }
    }
    cout << endl;



}