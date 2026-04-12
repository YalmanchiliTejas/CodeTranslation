#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++) cin >> S.at(i);

    for(char alphabet = 'a'; alphabet <= 'z'; alphabet++){
        int min = 50;
        for(auto str : S){
            int count = 0;
            for(auto c : str) if(c == alphabet) count++;
            if(min > count) min = count;
        }
        for(int i = 0; i < min; i++) cout << alphabet;
    }
    cout << endl;

    return 0;
}