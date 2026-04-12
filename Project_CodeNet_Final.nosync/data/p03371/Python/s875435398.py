a,b,c,x,y= map(int, input().split())

d = min(a+b,2*c)

a = min(a,2*c)
b = min(b,2*c)
s=min(x,y)*d + max(0,x-y)*a + max(0,y-x)*b
print(s)