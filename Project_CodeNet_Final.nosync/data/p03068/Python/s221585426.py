import math

n = int(input())
s = input()
k = int(input()) - 1
for i in range(n):
    print(s[i] if s[i] == s[k] else "*", end="")
