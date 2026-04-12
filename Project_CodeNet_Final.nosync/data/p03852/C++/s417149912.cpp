#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif // LOCAL

    char ch;
    ch=getchar();
    if(ch=='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u')
        printf("vowel");
    else
        printf("consonant");
    return 0;
}
