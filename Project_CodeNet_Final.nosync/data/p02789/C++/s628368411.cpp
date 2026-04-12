#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    if(n == m){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}