a,b,c,x,y = map(int,input().split())
s = [0 for i in range(4)]
s[0] = x*a+y*b
s[1] = a*max(0,x-y)+2*c*y
s[2] = 2*c*x+b*max(0,y-x)
s[3] = 2*c*max(x,y)
print(min(s))
