#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    map<int, int> m;
    set<int> s;
    while (scanf("%d,%d", &a, &b)) {
        if (a==0 && b==0) break;
        m[a]=-b;
        s.insert(-b);
    }
    while (scanf("%d", &a) != EOF) {
        int res=1;
        for (set<int>::iterator it=s.begin(); it != s.end(); ++it, res++)
            if (*it == m[a]) break;
        printf("%d\n", res);
        //printf("%d\n", distance(s.find(m[a]), s.begin())+1);
    }
    return 0;
}