#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 2e5+10;
int N, A[maxN];
 
int main()
{
cin >> N;
for (int i=1; i <= N; i++) cin >> A[i];
int x = N;
while (x > 0)
{
cout << A[x] << " ";
x -= 2;
}
if (x == -1) x += 3;
else x += 1;
while (x <= N)
{
cout << A[x] << " ";
x += 2;
}
}