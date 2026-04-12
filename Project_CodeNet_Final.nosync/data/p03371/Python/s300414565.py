a, b, c, x, y = map(int, input().split())

h = a*x+b*y
i = a*(x-min([x,y]))+b*(y-min([x,y]))+2*c*min([x,y])
j = 2*c*max([x, y])
print(min([h, i, j]))