a,b,c,x,y = map(int, input().split())
z = min(x,y)
print(min(a*x+b*y, a*(x-z)+b*(y-z)+2*c*z, 2*c*(x+y-z)))
