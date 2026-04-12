#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
while(true){
int n;
vector<int> s;
scanf("%d", &n);
if(n == 0)
break;
s.resize(n);
for(int i = 0; i < n; ++i)
scanf("%d", &s[i]);
sort(s.begin(), s.end());
int sum = 0;
for(int i = 1; i < n - 1; ++i)
sum += s[i];
printf("%d\n", sum / (n - 2));
}
return 0;
}