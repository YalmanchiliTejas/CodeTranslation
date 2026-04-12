import math

a, b, c, x, y = map(int, input().split())

cost_a = min(2*c,a)
cost_b = min(2*c,b)
cost_ab = min(2*c,cost_a+cost_b)
min_xy = min(x,y)

cost_res = 0
if 2*c < a+b:
    cost_res = min_xy * (2*c)
    cost_res += (x-min_xy)*cost_a+(y-min_xy)*cost_b
else:
    cost_res = min_xy * (a+b)
    cost_res += (x-min_xy)*cost_a+(y-min_xy)*cost_b
print(cost_res)