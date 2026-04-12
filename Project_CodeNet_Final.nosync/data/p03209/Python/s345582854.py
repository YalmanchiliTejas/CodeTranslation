# -*- coding: utf-8 -*-
N, X = map(int, input().split())

p = [0 for _ in range(N+1)]
b = [0 for _ in range(N+1)]
t = [0 for _ in range(N+1)]
p[0] = 1
t[0] = 1
idx = 0
for i in range(1,N+1):
    p[i] = p[i-1]*2 + 1
    b[i] = b[i-1]*2 + 2
    t[i] = p[i]+b[i]
    if X == t[i]:
        print(p[i])
        exit()
    if t[i-1] < X < t[i]:
        idx = i

if X <= N:
    print(0)
    exit()

start = X
ans = 0
for i in reversed(range(1,N+1)):
    if t[i] - i <= start <= t[i]:
        ans += p[i]
        print(ans)
        exit()

    if t[i]//2 == start:
        ans += p[i-1]
        print(ans)
        exit()

    if t[i]//2 + 1 == start:
        ans += p[i-1] + 1
        print(ans)
        exit()

    if t[i]//2 + 1 < start < t[i] - i:
        ans += p[i-1] + 1
        start = start - t[i-1] - 2
    else:
        start = start - 1

print(ans)

