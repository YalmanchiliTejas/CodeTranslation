#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    string S;
    cin >> S;
    if(S[0]!=S[1] || S[1]!=S[2]) cout << "Yes";
    else cout << "No";

    return 0;
}