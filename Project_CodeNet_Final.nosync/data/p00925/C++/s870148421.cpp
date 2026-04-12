#include <iostream>
#include <string>
#include <map>
#include <vector>
 
using namespace std;
 
string s;
int p;
int T;
 
int number()
{
    int res = s[p] - '0';
    p++;
    return res;
}
 
int formula()
{
    int res = number();
    for (;;) {
        if (s[p] == '*') {
            p++;
            res *= number();
        } else {
            break;
        }
    }
    return res;
}
 
int expr()
{
    int res = formula();
    for (;;) {
        if (s[p] == '+') {
            p++;
            res += formula();
        } else {
            break;
        }
    }
    return res;
}
 
int expr2()
{
    int res = number();
    for (;;) {
        if (s[p] == '+') {
            p++;
            res += number();
        }
        else if (s[p] == '*') {
            p++;
            res *= number();
        }
        else {
            break;
        }
    }
    return res;
}
 
int main()
{
    cin >> s >> T;
 
    bool l1, l2;
    p = 0;
    l1 = expr() == T;
    p = 0;
    l2 = expr2() == T;
 
    if (l1 && l2) cout << "U" << endl;
    if (l1 && !l2) cout << "M" << endl;
    if (!l1 && l2) cout << "L" << endl;
    if (!l1 && !l2) cout << "I" << endl;
}