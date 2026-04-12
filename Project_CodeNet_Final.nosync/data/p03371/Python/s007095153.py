a,b,c,x,y = map(int, input().split())
if max(x,y) == x:
    d=a
else:
    d=b
print(min((a*x)+(b*y),2*c*min(x,y)+(abs(x-y)*d),2*c*max(x,y)))