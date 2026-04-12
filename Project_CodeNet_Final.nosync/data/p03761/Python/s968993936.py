# coding: utf-8
from collections import Counter
alp=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
INF=10**9
D=[]

N=int(input())
for i in range(N):
    S=list(input())
    D.append(Counter(S))
L=[INF for i in range(26)]

for i in range(26):
    for j in range(N):
        L[i]=min(L[i],D[j][alp[i]])
ans=""

for i in range(26):
    for j in range(L[i]):
        ans+=alp[i]

print(ans)