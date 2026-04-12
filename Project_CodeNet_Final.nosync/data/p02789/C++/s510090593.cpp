#include <iostream>
#include <vector>
#include <string>
#define FIN freopen("inputs.txt", "r", stdin)
using namespace std;
typedef pair<int, int> P;
int m ,  n;
int main(){
//FIN;
    cin>>n>>m;
    if(m>=n) cout<<"Yes\n";
    else  cout<<"No\n";
    return 0;
}