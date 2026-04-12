a, b, c, x, y = map(int, input().split())

single = a*x+b*y
pair_max = 2*c*max(x, y)
pair_min = 2*c*min(x, y) + a*abs(x-y)*(x>y) + b*abs(x-y)*(x<y)

print(min(single, pair_max, pair_min))