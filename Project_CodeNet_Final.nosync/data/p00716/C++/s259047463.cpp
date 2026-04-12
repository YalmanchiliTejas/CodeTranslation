#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <cfloat>
using namespace std;

int solve(int money, int year, vector<int>& a, vector<double>& b, vector<int>& c)
{
    int n = a.size();
    int ret = 0;
    for(int i=0; i<n; ++i){
        int balance = money; // c
        int interest = 0;    // q
        for(int j=0; j<year; ++j){
            interest += balance * b[i];
            if(a[i] == 1){
                balance += interest;
                interest = 0;
            }
            balance -= c[i];
        }
        balance += interest;
        ret = max(ret, balance);
    }
    return ret;
}

int main()
{
    int m;
    cin >> m;
    for(int i=0; i<m; ++i){
        int money, year, n;
        cin >> money >> year >> n;
        vector<int> a(n), c(n);
        vector<double> b(n);
        for(int i=0; i<n; ++i)
            cin >> a[i] >> b[i] >> c[i];

        cout << solve(money, year, a, b, c) << endl;
    }
}