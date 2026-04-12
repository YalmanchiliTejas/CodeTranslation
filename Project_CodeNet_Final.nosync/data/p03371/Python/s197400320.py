a, b, c, x, y = map(int, input().split())
res = 2*c*min(x, y) if a+b >= 2*c else (a+b)*min(x, y)
print(res+(x-y)*min(2*c, a)) if x >= y else print(res+(y-x)*min(2*c, b))