# -*- coding: utf-8 -*-
"""
Created on Sat Sep 19 22:03:19 2020

@author: liang
"""

N, X, M = map(int,input().split())
mod_set = {X}
mod_lis = [X]
A = [0]*(10**6+1)
A[0] = X
flag = False
#for i in range(1,N):
i = 1
for i in range(1,min(10**6,N)):
    tmp = A[i-1]**2%M
    if tmp in mod_set:
        flag = True
        break
    A[i] = tmp
    mod_set.add(tmp)
    mod_lis.append(tmp)

if flag:
    j = mod_lis.index(tmp)
else:
    j = i
T = i - j
ans = 0
if T != 0:  
    #print("A")
    ans += sum(mod_lis[:j])
    T_sum = sum(mod_lis[j:])
    """
    【切り捨て演算は必ず()をつけて先に計算】
    """
    ans += T_sum * ((N-j)//T)
    #print((N-j)//T, T_sum)
    T_lis = mod_lis[j:i]   
    ans += sum(T_lis[:(N-j)%T])
else:
    #print("B")
    ans = sum(mod_lis)
   # print(mod_lis)
#print(T_lis)
#print((N-j)%T)
#print(T_lis[:10])
print(ans)
#print(T_sum)
#print(sum(T_lis))