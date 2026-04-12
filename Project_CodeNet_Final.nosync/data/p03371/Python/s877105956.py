a, b, c, x, y = map(int, input().split())
i = a*x+b*y
j = c*min(x, y)*2+a*(x-min(x, y))+b*(y-min(x, y))
k = c*max(x, y)*2
print(min(i, j, k))
