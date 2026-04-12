a,b,ab,x,y = map(int,input().split())

if a+b <= 2*ab:
    print(a*x+b*y)
else:
    print(min(max(a*(x-y),b*(y-x)),2*ab*abs(x-y)) + 2*ab*min(x,y))

