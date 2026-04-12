#include <iostream>
#include <cstdio>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>

#include <numeric>
#include <algorithm>
#include <functional>

#include <cctype>

#include <complex>
#include <string>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rep(i,n) for(unsigned int i=0;i<(n);i++)
#define tr(it,container) for(typeof(container.begin()) it = container.begin(); \
                                                  it != container.end(); ++it)

typedef long long ll;
typedef complex<double> P;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
const double EPS = 1e-9;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int daysleap[] = {31,29,31,30,31,30,31,31,30,31,30,31};

string hidari = "qwertasdfgzxcvb";
string migi = "yuiophjklnm";

bool phidari(char c){
    return find(all(hidari),c)!=hidari.end();
}

int main(){
    while(true){
        string s;
        cin >> s;
        if(s=="#") break;
        bool fhidari = phidari(s[0]);
        int c = 0;
        for(int i=0;i<s.length();i++){
            bool ishidari = phidari(s[i]);
            if(ishidari != fhidari) c++;
            fhidari = ishidari;
        }
        cout << c << endl;
    }
    return 0;
}