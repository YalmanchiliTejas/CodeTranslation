#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define REP(i,N) for(int i = 0; i < N; i++)

int main(){
    // string strs[50];
    int alphabets[50][26] = {};//alphabets[i][j]は文字列iには'a'+jが入っている文字列を表す
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.size(); j++){
            alphabets[i][tmp[j]-'a']++;
        }
        // cout << endl;
    }
    for(int i = 0; i < 26; i++){
        int min = 999;
        for(int j = 0; j < n; j++){
            if(alphabets[j][i] < min) min = alphabets[j][i];
        }
        char tmp = 'a' + i;
        for(int j = 0; j < min; j++){
            cout << tmp;
        }
    }
    cout << endl;
    return 0;
}
