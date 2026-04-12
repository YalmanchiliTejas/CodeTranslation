a,b,c,x,y = map(int,input().split())

res = 0
res += min(a+b,2*c)*min(x,y)
if x >= y:
    res += min(2*c*(x-y),a*(x-y))
else:
    res += min(2*c*(y-x),b*(y-x))

print(res)