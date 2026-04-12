#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int space = 0;
    int width = 0;
    int between = 0;
    
    cin >> space;
    cin >> width;
    cin >> between;
    
    space -= between;
    
    cout << space / (width + between) << endl;
    
    return 0;
}