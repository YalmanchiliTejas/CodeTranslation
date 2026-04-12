#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll long long
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if((10*b+c)%4==0){
      cout << "YES";
    }else{
      cout << "NO";
    }
    return 0;
}
