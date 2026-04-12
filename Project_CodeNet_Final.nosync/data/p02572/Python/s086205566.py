import math
import itertools
import sys
n = int(input())
a = list(map(int, input().split()))
ans = 0
all = 0
for i in a:
    all += i
for i in a:
    all -= i
    ans += i*all
    if(ans > 10**9+7):
        ans %= 10**9+7
print(ans)
