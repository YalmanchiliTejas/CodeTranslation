import math
from collections import Counter

n = int(input())
s = [Counter(list(input())) for _ in range(n)]
a = [math.inf] * 26
flag = [0] * 26
ans = ""
for i in s:
    ke = list(i.keys())
    val = list(i.values())
    for j, k in enumerate(ke):
        a[ord(k) - 97] = min(a[ord(k) - 97], val[j])
        flag[ord(k) - 97] += 1
for v in range(len(a)):
    if a[v] != math.inf and flag[v] >= n:
        ans += a[v] * chr(97 + v)
print(ans)