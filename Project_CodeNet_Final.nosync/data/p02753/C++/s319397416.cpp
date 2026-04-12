#include <iostream>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, k, n) for (int i = k; i <= n; ++i)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[10];
    
    cin >> str;
    
    if(str[0] == 'A' && str[2] == 'B'){
        cout << "Yes" << "\n";
    }else if(str[0] == 'B' && str[2] == 'A'){
        cout << "Yes" << "\n";
    }else if(str[0] == 'A' && str[2] == 'A' && str[1] == 'B'){
        cout << "Yes" << "\n";
    }else if(str[0] == 'B' && str[2] == 'B' && str[1]=='A'){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

    return 0;
}