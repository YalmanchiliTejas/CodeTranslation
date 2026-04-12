#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    string s;
    for(int i=0; i<n; ++i){
        static char a;
        cin >> a;
        s.push_back(a);
    }
    cin >> k;
    char sp = s.at(k-1);
    string output;
    for(int i=0; i<n; ++i){
        if(s.at(i)==sp) output.push_back(sp);
        else output.push_back('*');
    }
    cout << output << endl;
    return 0;
}
