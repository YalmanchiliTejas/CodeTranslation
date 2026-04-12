a,b,c,x,y = map(int,input().split())
res = min(a+b,2*c)*min(x,y)
if x > y:
    res += min(a,2*c)*(x-y)
else:
    res += min(b,2*c)*(y-x)
print(res)