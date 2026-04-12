# -*- coding: utf-8 -*-
"""
Created on Thu Aug  9 23:51:35 2018

@author: Yuki
"""

A, B, AB, Acnt, Bcnt =map(int, input().split())

res = []
# AをAcnt枚, BをBcnt枚買う場合
res.append(A*Acnt+B*Bcnt)

# AcntとBcntの少ない方に到達するまでABを買い、残りは普通の買う場合
if Acnt >= Bcnt:
    res.append(Bcnt*2*AB+(Acnt-Bcnt)*A)
else:
    res.append(Acnt*2*AB+(Bcnt-Acnt)*B)

# 多い方までABを買う
res.append(max(Acnt, Bcnt)*2*AB)
print(min(res))