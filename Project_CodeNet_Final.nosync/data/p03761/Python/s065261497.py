# -*- coding: utf-8 -*-

n = int(input())
s = [0]*n
for i in range(n):
    s[i] = list(input())

def list_intersection(a,b):
    c = []
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] == b[j]:
                c.append(a[i])
                a[i] = "_"
                b[j] = "&"
    return c

if n == 1:
    ans = s[0]
    ans.sort()
elif n == 2:
    ans = list_intersection(s[0],s[1])
    ans.sort()
else:
    ans = list_intersection(s[0],s[1])
    for i in range(2,n):
        ans = list_intersection(ans,s[i])
    ans.sort()

print("".join(ans))
