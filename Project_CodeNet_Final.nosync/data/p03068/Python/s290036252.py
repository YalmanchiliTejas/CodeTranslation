# -*- coding: utf-8 -*-


# Parse and assignment for input
n = int(input())
s = input()
k = int(input())
x = s[k-1]

ans = ""
for i in s :
    if i == x :
        ans += i
    else:
        ans += '*'
print(ans)