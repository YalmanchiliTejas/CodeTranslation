# coding: utf-8
N=int(input())
HList=list(map(int, input().split()))
MAX=0
ANS=0
for i in range(N):
    if HList[i]>=MAX:
        MAX=HList[i]
        ANS+=1
        
print(ANS)
