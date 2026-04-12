#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    int H[20];
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int ans = 0;
    int MAX = 0;
    for(int i=0;i<N;i++){
        MAX = max(MAX,H[i]);
        if(MAX == H[i]){
            ans++;
        }
    }
    cout << ans << endl;
return 0;
}

