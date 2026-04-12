import math
import sys
n = int(input())
s = input()
k = int(input())
x = ""
for i in s:
    if i == s[k-1]:
        x += s[k-1]
    else:
        x += "*"
print(x)
