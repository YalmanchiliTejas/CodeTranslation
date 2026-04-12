# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))
N = int(input())
H = inpl()
max_ = 0
ans = 0
for h in H:
    ans += h >= max_
    max_ = max(h, max_)
print(ans)