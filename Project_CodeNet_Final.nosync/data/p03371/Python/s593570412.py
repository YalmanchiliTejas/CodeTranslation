a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, c*2*max(x,y), c*2*min(x,y)+abs(x-y)*max([[x,a],[y,b]],key=lambda s:s[0])[1]))