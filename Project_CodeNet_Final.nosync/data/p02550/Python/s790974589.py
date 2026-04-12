#!/usr/bin/env python
n, x, m = map(int, input().split())

tmp = x 
cnt = 0 
dup = 0 
a = [x] 
while True:
    tmp = (tmp*tmp)%m
    if tmp in a:
        dup = tmp 
        break
    cnt += 1
    a.append(tmp)

di = 0 
for i in range(len(a)):
    if a[i] == dup:
        di = i 

# block sum
b = []
bs = 0 
for i in range(di, len(a)):
    bs += a[i]
    b.append(a[i])

# block length
bl = len(a)-di
sumbl = 0 

ans = 0 
for i in range(di):
    ans += a[i]
ans += (n-di)//bl * bs
for i in range((n-di)%bl):
    ans += b[i]

print(ans)
