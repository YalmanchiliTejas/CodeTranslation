from sys import stdin
N = int(input())
S = input()
K = int(input())
ans= ""
for e in S:
    if e == S[K-1]:
        ans += e
    else:
        ans += "*"
print(ans)
