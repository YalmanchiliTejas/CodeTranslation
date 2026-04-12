#include <bits/stdc++.h>
#define rep(i,n) for (int i =0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    string st;
    cin >> st;
    bool fl_a,fl_b;
    fl_a = false;
    fl_b = false;
    
    for(auto x:st){
        if(x == 'A') fl_a=true;
        if(x == 'B') fl_b=true;
    }

    if (fl_a && fl_b)
        cout << "Yes" <<endl;
    else
        cout << "No" <<endl;
    

    return 0;
}