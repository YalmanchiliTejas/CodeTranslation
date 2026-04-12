a,b,c,x,y = list(map(int, input().split()))

s1 = a*x + b*y
s2 = c*(max(x,y)*2)
if x>y:
    s3 = c*(y*2) + a*(x-y)
elif y>x:
    s3 = c*(x*2) + b*(y-x)
else: s3 = 10**10

print(min(s1,s2,s3))