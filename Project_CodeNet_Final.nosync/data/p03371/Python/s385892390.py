# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 11:16:07 2020

@author: liang
"""
###煩雑 => 列挙して最小値を出力
"""
A, B, C, X, Y = map(int,input().split())
if A + B > 2*C:
    if X > Y :
        if A < 2 * C:
            ans = Y * C * 2 + abs(X-Y) * A
        else:
            ans = X * C * 2  ##
    else:
        if B < 2 * C:
            ans = X * C * 2 + abs(X-Y) * B
        else:
            ans = Y * C * 2 ##
else:
    ans = X * A + Y * B 
print(ans)
"""
A, B, C, X, Y = map(int,input().split())
if A + B > 2*C:
    ans1 = max(X,Y) * C * 2  #条件分岐が減る
    if X > Y :
            ans2 = Y * C * 2 + abs(X-Y) * A           
    else:
            ans2 = X * C * 2 + abs(X-Y) * B  
    print(min(ans1,ans2)) #print()が分岐する
else:   
    ans1 = X * A + Y * B 
    print(ans1)