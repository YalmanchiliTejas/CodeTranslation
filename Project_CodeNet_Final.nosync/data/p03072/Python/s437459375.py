# coding: utf-8
n = int(input())
hs = list(map(int, input().split()))
n = 1
for i, h in enumerate(hs, 1):
    if i == 1:
        continue
    is_exist = False
    for j in hs[:i-1]:
        if j > h:
            is_exist = True
            break
    if not is_exist:
        n += 1

print(n)