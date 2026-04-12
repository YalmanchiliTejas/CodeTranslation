#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    char curr;
    cin >> curr;
    for(int i=0; i<n-1; i++){
        char c;
        cin >> c;
        curr = (curr == 'T' and c == 'F')? 'F': 'T';
    }
    cout << curr << endl;
    return 0;
}
