a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, c*2*max(x,y), c*2*min(x,y)+abs(x-y)*(a if x>y else b)))