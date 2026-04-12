#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int n; cin >> n; deque<int> a;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;

        if (n&1){
            if (i&1) a.push_back (input);
            else     a.push_front(input);
        } else {
            if (i&1) a.push_front(input);
            else     a.push_back (input);
        }
    }

    for (deque<int>::iterator i = a.begin(); i != a.end(); i++){
        if (i != a.begin()) cout << ' ';
        cout << *i;
    } cout << endl;

    return 0;
}
