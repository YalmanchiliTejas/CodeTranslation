a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, max(x,y)*2*c, 2*c*x+b*(y-x) if x < y else 2*c*y+a*(x-y)))