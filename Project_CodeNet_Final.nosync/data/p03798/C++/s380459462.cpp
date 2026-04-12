#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

char flip_animal(char c){
    return c == 'S' ? 'W' : 'S';
}
char flip_question(char c){
    return c == 'o' ? 'x' : 'o';
}

string solve(int n, const string& q, char a0, char a1) {
    string a(n, '?');
    a[0] = a0;
    a[1] = a1;

    for(int i = 1; i < n - 1; i++){
        char flip = a[i] == 'S' ? q[i] : flip_question(q[i]);
        a[i+1] = flip == 'o' ? a[i-1] : flip_animal(a[i-1]);
    }

    char flip1 = a[n-1] == 'S' ? q[n-1] : flip_question(q[n-1]);
    char next1 = flip1 == 'o' ? a[n-2] : flip_animal(a[n-2]);

    char flip2 = a[0] == 'S' ? q[0] : flip_question(q[0]);
    char next2 = flip2 == 'o' ? a[n-1] : flip_animal(a[n-1]);
    return next1 == a[0] && next2 == a[1] ? a : "";
}

int main(void) {
    int n;
    cin >> n;

    string q;
    cin >> q;

    string a;
    a = solve(n, q, 'S', 'S');
    if(!a.empty()){
        cout << a << endl;
        return 0;
    }
    a = solve(n, q, 'S', 'W');
    if(!a.empty()){
        cout << a << endl;
        return 0;
    }
    a = solve(n, q, 'W', 'S');
    if(!a.empty()){
        cout << a << endl;
        return 0;
    }
    a = solve(n, q, 'W', 'W');
    if(!a.empty()){
        cout << a << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
