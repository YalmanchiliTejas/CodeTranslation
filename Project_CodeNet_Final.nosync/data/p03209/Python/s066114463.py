# coding: utf-8
# Your code here!

N, X = map(int, input().split())

L = []
P = []

for i in range(N):
    if i == 0:
        L.append(1)
        P.append(1)
        continue
    else:
        L.append(L[i-1] * 2 + 3)
        P.append(P[i-1] * 2 + 1)

def g(k, x):
    if x == 0:
        return 0
    
    if k == 0:
        return 1
    
    if x < L[k-1] + 2:
        return g(k-1, x-1)
    
    if x == L[k-1] + 2:
        return P[k-1] + 1
    
    if x > L[k-1] + 2:
        return P[k-1] + 1 + g(k-1, x - (L[k-1] + 2))

print(g(N, X))
