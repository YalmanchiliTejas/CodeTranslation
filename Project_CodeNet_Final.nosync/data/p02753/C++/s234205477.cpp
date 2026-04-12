#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

int main(){
    char a, b, c;
    cin >> a >> b >> c;
    cout << (a == b && b == c ? "No" : "Yes") << '\n';
}
