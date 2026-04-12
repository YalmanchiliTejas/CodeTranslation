#include<bits/stdc++.h>


using namespace std;
#define max 10005
int main(){
    int n;
    cin >> n;
    int temp = n/15;
    if(temp) cout << (n*800)-(temp*200) << endl;
    else
      cout << (n*800) << endl;
    return 0;
}