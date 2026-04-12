# coding: utf-8

n = int(input())
h = list(map(int, input().split()))

ans = 0

for i in range(n):
    ok = True
    for j in range(0, i):
        if h[j] > h[i]:
            ok = False
            break
    if ok:
        ans += 1

print(ans)
