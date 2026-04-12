
# -*- coding: utf-8 -*-
a,b,ab,x,y = list(map(int, input().split()))
# A、Bそれぞれをそのまま買ったときのコスト
cost=a*x + b*y
# ABだけで済ませた場合のコスト
for i in range(0, max(x, y)+1):
    cost = min(cost, a*max((x-i),0) + b*max((y-i),0) + ab*2*i)

print(cost)