import sys

N=int(input())
S=input()
K=int(input())

L = []
for i in range(N):
    if S[i] != S[K-1]:
        L.append("*")
    else:
        L.append(S[i])

ans = ''
for i in range(N):
    ans += L[i]

print(ans)