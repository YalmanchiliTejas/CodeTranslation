#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c=s[k-1];
    for(int i=0;i<n;i++){
        cout << (s[i]==c?c:'*');
    }
    cout << endl;
    return 0;
}