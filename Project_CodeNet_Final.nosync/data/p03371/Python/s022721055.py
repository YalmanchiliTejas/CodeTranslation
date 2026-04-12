a, b, c, x, y = [int(x) for x in input().split()]

if a + b < c*2:
    res = a*x + b*y
else:
    min_c = min(x, y)
    ab_cost = min_c * 2 * c
    rem = max(x-min_c, y-min_c)
    if x > y:
        rem_cost = min(rem * a, rem*2*c)
    else:
        rem_cost = min(rem*b, rem*2*c)
    res = ab_cost + rem_cost
print(res)