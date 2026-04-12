#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
while(true) {
int n;
scanf("%d", &n);
if(n == 0)
break;
priority_queue<int> q[2];
int s[2] = {0};
int prev = -1;
for(int i = 0; i < n; ++i) {
int c, d;
scanf("%d", &c);
d = (c + 1) % 2;
if(i % 2 == 0) {
if(prev != c)
q[c].push(i);
} else {
if(prev != c) {
int l = q[d].top();
q[d].pop();
int re = i - l;
s[c] += re;
s[d] -= re;
if(l == 0)
q[c].push(0);
}
}
s[c] += 1;
prev = c;
}
printf("%d\n", s[0]);
}
return 0;
}