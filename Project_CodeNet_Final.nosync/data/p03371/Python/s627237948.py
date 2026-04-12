a, b, c, x, y = map(int, input().split())
print(min([a*x+b*y, a*(x-min([x,y]))+b*(y-min([x,y]))+2*c*min([x,y]),2*c*max([x, y])]))