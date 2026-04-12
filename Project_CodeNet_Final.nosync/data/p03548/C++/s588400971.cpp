#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define B       (cout << "Sehen Sie mich!" << endl)
#define VB(val) (cout << val << endl)

inline int ctoi(const char c){
        if('0' <= c && c <= '9') return (c -'0');
        return -1;
}

int main()
{
        int x, y, z;
        int ret = 0;
        cin >> x >> y >> z;

        x = x - z;
        while (x >= y + z) {
                x = x - y - z;
                ret++;
        }
        VB(ret);
}