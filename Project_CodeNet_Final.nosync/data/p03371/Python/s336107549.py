a,b,c,x,y = map(int,input().split())

sum_ab = a + b
double_c = c * 2
cheaper = sum_ab if sum_ab <= double_c else double_c
lesser = x if x < y else y
moreer = x if x >= y else y
base_cost = cheaper * lesser
additional = 0
if x - y > 0:
  additional = (x-y) * a
else:
  additional = (y-x) * b
total_p1 = base_cost + additional
total_p2 = moreer * double_c
print(min(total_p1, total_p2))