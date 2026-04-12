# -*- coding: utf-8 -*-

n = int(input())
s = input()
k = int(input())
temp = []

for i in range(n):
    if s[i]!=s[k-1] :
        temp.append("*")
    else:
        temp.append(s[k-1])

ans = "".join(temp)

print(ans)