#!/usr/bin/env python3
n, k = map(int, input().split())
"""
bを固定して、aの数を数える
(b-k) * (N//b) + min(0,n%b - k +1)
注意するのは、k >= b なら0 
"""
ans = 0
# b を動かす
for b in range(k + 1, n + 1):
    ans += (b - k) * (n // b) + max(0, n % b - k + 1)
    # print(ans, b)
if k == 0:
    print(n ** 2)
else:
    print(ans)
