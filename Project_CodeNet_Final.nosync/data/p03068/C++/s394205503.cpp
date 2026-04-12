#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string lb;
    string str;
    int kth;

    cin >> n;
    getline(std::cin, lb);
    getline(std::cin, str);
    cin >> kth;

    char target_c = str[kth-1];

    for(int i=0; i<n; ++i){
        if(str[i] == target_c){
            cout << target_c;
        }else{
            cout << '*';
        }
    }
    cout << endl;
    return 0;
}