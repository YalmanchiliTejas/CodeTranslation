#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    if(b < a) cout << "No";
    if(b == a) cout << "Yes";

	return 0;
}

