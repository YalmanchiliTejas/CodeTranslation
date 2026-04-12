# coding: utf-8
import collections

n=int(input())
S=[]
C=[]
alph=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
for i in range(n):
    S.append(list(input()))
    C.append(collections.Counter(S[i]))

ans=""
# print(S)
# print(C)

for i in range(len(alph)):
    mozi=alph[i]
    minc=1000
    for j in range(n):
        minc=min(minc,C[j][mozi])
    
    for j in range(minc):
        ans+=mozi

print(ans)