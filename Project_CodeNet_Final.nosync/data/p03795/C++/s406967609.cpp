
#include <iostream>
using namespace std;
int main() {
    int dish,service=0;
    cin>>dish;
    service=(dish/15)*200;
    dish=dish*800;
    cout<<dish-service<<endl;
    return 0;
}