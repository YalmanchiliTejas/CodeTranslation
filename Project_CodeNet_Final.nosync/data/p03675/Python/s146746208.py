# -*- coding: utf-8 -*-
n = int(input())
a = input().split()
b = [a[0], []]
last = b[1]

for i in range(1,n):
    if i%2==0:
        last.append(a[i])
        last.append([])
        last = last[1]
    else:
        b = [a[i],b]

ret = []
for _ in range(n):
    ret.append(b[0])
    b = b[1]

if n%2==0:
    print(" ".join(ret))
else:

    print(" ".join(ret[::-1]))
