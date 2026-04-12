"""
A = a1,a2,a3,a4,...
同じ色のとき、i<jならai<aj

が成り立つときの最小の色の数
"""

from bisect import bisect_right

prev = 10**9+7
cnt = 0
As = [-prev]
n = int(input())
for _ in range(n):
    a = int(input())
    update = bisect_right(As,-a)
    if update-1 == cnt:
        As.append(-a)
        cnt += 1
    else:
        As[update] = -a 
    prev = a

print(cnt)

