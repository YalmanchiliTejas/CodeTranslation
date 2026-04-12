#include <iostream>
using namespace std;

#define print(x) cout << (x) << '\n'
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(__null);
    
    int x; cin >> x;
    if (x == 3 || x == 5 || x == 7) print("YES");
    else print("NO");
    
    return 0;
}