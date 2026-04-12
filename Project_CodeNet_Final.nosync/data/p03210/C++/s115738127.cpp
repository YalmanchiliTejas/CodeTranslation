#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void print_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << char(v[i]+97);
    }
    cout << endl;
}

int main()
{
    int x;
    cin >> x;
    if(x==3 || x==5 || x==7) cout << "YES";
    else cout << "NO";


    return 0;
}
