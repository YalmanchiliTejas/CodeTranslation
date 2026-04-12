a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, a*max(x-y, 0)+b*max(y-x, 0)+c*2*min(x, y), c*2*max(x, y)))