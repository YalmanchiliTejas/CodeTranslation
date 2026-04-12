# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

a,b,c,x,y = list(map(int,input().split()))

min_cost = 5000 * 100000 * 2
#abピザを2i枚買う時残り必要な額を計算する

for i in range(100001):
    zan_a = max(x-i,0)
    zan_b = max(y-i,0)
    min_cost = min((a*zan_a+b*zan_b+c*i*2),min_cost)
print(min_cost)