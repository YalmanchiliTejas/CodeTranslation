#include <iostream>
#include <sstream>

using namespace std;

int main(void){
    int n;
    cin >> n ;
    cin.ignore();
    int h;
    int max = 0;
    int result = 0;
    for(int i = 0; i<n; i++){
        cin >> h;
        if( max <= h ){
            result += 1;
            max = h;
        }
    }
    cout << result << endl;
}