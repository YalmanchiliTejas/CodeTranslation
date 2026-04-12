# coding: utf-8
N = int(input())
H = list(map(int, input().split()))
ans = 0
min = 0
for h in H:
    if min <= h:
        ans += 1
        min = h
print(ans)