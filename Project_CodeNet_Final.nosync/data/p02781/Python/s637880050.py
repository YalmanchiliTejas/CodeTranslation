# -*- coding: utf-8 -*-
"""
Created on Wed Feb 12 17:17:55 2020

@author: matsui
"""
def check(N,K):
    ans=0
    for i in range(N+1):
        c=0
        for s in str(i):
            if int(s)!=0: c+=1
        if c==K: ans+=1
    return ans

N=input()
L=len(N)
K=int(input())

ans=0
if K==1:
    ans=int(N[0])+(L-1)*9
           
if K==2:
    dp=[0]*(L+1)
    for i in range(2,L):
        dp[i]=9*9*(i-1)
          
    dp[L]=(int(N[0])-1)*9*(L-1)
    
    for i in range(1,L):
        if int(N[i])!=0:
            dp[L]+=int(N[i])+9*(L-i-1)
            break
     
    ans=sum(dp)
    
if K==3:
    dp=[0]*(L+1)
    for i in range(3,L):
        dp[i]=9*(dp[i-1]/9+9*9*(i-2))
        
        
    dp[L]=(int(N[0])-1)*(dp[L-1]/9+9*9*(L-2))
    
    for i in range(1,L):
        if int(N[i])!=0:
            dp[L]+=(int(N[i])-1)*9*(L-i-1)+9*9*(L-i-1)*(L-i-2)/2
            break
        
    for j in range(i+1,L):
        if int(N[j])!=0:
            dp[L]+=int(N[j])+9*(L-j-1)
            break
        
    
    
           
    ans=sum(dp)
    
print(int(ans))
#print(check(int(N),K))