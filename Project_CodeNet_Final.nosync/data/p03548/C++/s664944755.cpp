#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int sum = z;
    int people = 0;
    while(sum + y + z <= x){
        sum += y + z;
        people++;
    }
    cout << people << endl;
}