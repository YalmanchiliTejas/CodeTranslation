#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#define ll long long
#define MODD 1000000007
using namespace std;

int main() {
    int r,g,b;
    cin>>r>>g>>b;
    if ((r*100+g*10+b)%4==0)
        printf("YES\n");
    else
        printf("NO\n");
}