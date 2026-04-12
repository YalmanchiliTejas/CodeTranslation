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
"""
【for文のループ用の変数を、
　●for文外で使ったり
 ●for文内で書き換えたり
 してはいけない】
 (理由)
●for文外で使うとき、for文に入らない入力値の場合
　　【未定義】
　となり、エラーが出る。　
 ⇒　【for文外で定義済み】の他の変数に保存する
●for文内で書き換えると、ループが壊れてしまう
 ⇒　一旦別の変数に保存し、その変数を書き換える

【整数の切り捨て演算は計算順序に注意】
*ans += T_sum * (N-j)//T
　⇒T_sum * (N-j)　を Tで割っているのでダメ
<対策 1: 切り捨て演算は括弧で囲む>
 ⇒ans += T_sum * ( (N-j)//T )
<対策 2: 切り捨て演算は予め計算しておく>
 ●divmod(a,b) => return (a//b,a%b)

"""
l = 1
for i in range(1,min(10**6,N)):
    l = i
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
    j = l
T = l - j
ans = 0
if T != 0:  
    #print("A")
    ans += sum(mod_lis[:j])
    T_sum = sum(mod_lis[j:])
    q, r = divmod(N-j,T)
    ans += T_sum * q
    #print((N-j)//T, T_sum)
    T_lis = mod_lis[j:]   
    ans += sum(T_lis[:r])
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