#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z; cin >> x >> y >> z;
    int count = 0;
    while(y * count + z * (count+1) < x)
        count++;
    
    if(y * count + z * (count+1) > x)
        count--;
    
    cout << count << endl;
}
