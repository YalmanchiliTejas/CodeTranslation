#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<stw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値

using namespace std;

int main(void){
    string str;
    cin >> str;
    if(str[0]==str[1]&&str[1]==str[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}