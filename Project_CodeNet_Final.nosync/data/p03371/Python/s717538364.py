a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, c*2*x+b*max(0,y-x), c*2*y+a*max(0,x-y)))
