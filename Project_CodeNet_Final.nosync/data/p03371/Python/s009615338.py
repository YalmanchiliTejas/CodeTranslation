a, b, c, x, y = map(int, input().split())
m, ab = min(x, y), max(x, y)*c*2
print(min(ab, a*x+b*y, m*c*2+a*(x-m)+b*(y-m)))