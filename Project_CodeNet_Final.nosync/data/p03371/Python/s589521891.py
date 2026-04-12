#abc095 c
a,b,c,x,y=map(int,input().split())
price=0
d=min(x,y)
if a+b>c*2:
    price+=2*c*d
else:
    price+=(a+b)*d

if x>y:
    price+=min(a*(x-y),2*c*(x-y))
else:
    price+=min(b*(y-x),2*c*(y-x))
print(price)
    