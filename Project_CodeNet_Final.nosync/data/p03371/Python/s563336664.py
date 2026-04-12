from collections import Counter

a, b, ab, x, y = map(int, input().split())

if a+b >= ab*2:
    if x < y:
        less, more = x, y
        cost_l, cost_m = a, b
    else:
        less, more = y, x
        cost_l, cost_m = b, a
    
    cost = less*ab*2
    more -= less
    less = 0

    if cost_m < ab * 2:
        cost += more*cost_m
    else:
        cost += more*ab*2

    print(cost)
else:
    print(a*x+b*y)