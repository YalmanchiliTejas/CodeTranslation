import math
import sys
N = int(input())
s = input()
k = int(input())
t = s[k-1]
u = ""
for i in s:
    if i == t:
        u += i
    else :
        u += '*'
print(u)

