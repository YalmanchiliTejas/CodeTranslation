#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

template <class T> T streamvar(std::istream& in)
{
    if (!in) {
        cerr << "invalid istream" << endl;
        exit(1);
    }
    T tmp;
    in >> tmp;
    if (in.fail()) {
        cerr << "no var" << endl;
        exit(1);
    }
    return tmp;
}
template <class T> void streamvec(std::istream& in, std::vector<T> &v)
{
    string s;

    if (!in) {
        cerr << "invalid istream" << endl;
        exit(1);
    }
    getline(in, s);
    if (in.fail()) {
        cerr << "no line" << endl;
        exit(1);
    }
    istringstream is(s);
    while (1) {
        T tmp;
        is >> tmp;
        if (is.fail())
            break;
        v.push_back(tmp);
    }
}

int main(void)
{
    vector<long long> v;
    streamvec(cin, v);
    if (v[0] < v[1]) {
        cout << "a < b" << endl;
    } else if (v[0] > v[1]) {
        cout << "a > b" << endl;
    } else {
        cout << "a == b" << endl;
    }
    return 0;
}