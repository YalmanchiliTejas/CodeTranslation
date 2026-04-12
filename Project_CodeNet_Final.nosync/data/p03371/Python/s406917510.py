a,b,ab,x,y = map(int,input().split())
price =0
if(a+b>2*ab):
    price = 2*ab*min(x,y)
    min = min(x,y)
    x -= min
    y -= min
    if(x>=y and a<2*ab):
        price += a*x
    elif(y>x and b<2*ab):
        price += b*y
    else:
        price += 2*ab*max(x,y)
else:
    price += a*x+b*y
print(price)
