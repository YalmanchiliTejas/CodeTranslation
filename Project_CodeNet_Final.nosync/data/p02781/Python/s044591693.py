# -*- coding: utf-8 -*-
from collections import defaultdict

N=raw_input()
K=input()

dp=defaultdict(lambda: 0)  #未満T or F , i桁目, 0でない数値がちょうどk個

l=len(N)

for i in range(l):
    x=int(N[i])
    i+=1
    if i==1:
        if x==1:
            dp[("T",i,0)]=1
            dp[("F",i,1)]=1
        else:
            dp[("T",i,0)]=1
            dp[("T",i,1)]=x-1
            dp[("F",i,1)]=1
    else:
        for k in range(K+1):
            dp[("T",i,k)]+=dp[("T",i-1,k)]
            dp[("T",i,k+1)]+=dp[("T",i-1,k)]*9
            if 0<x:
                dp[("T",i,k+1)]+=dp[("F",i-1,k)]*(x-1) #k桁目の数字pが0<p<xなのは、x-1通り
                dp[("T",i,k)]+=dp[("F",i-1,k)]  #k桁目の数字pが0の場合は1通り
                dp[("F",i,k+1)]+=dp[("F",i-1,k)]*1 #k桁目の数字p=xの場合はゼロでない数字が1個増える
            else: #k桁の目の数字xが0の場合
                dp[("F",i,k)]+=dp[("F",i-1,k)]*1
        
print dp[("T",l,K)]+dp[("F",l,K)]
