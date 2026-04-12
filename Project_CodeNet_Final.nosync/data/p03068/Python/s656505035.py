# coding: utf-8
# Your code here!
N = int(input())
S = input()
K = int(input())

ans = ""
x = S[K - 1]
for s in S:
    if s != x:
        ans += "*"
    else:
        ans += s

print(ans)