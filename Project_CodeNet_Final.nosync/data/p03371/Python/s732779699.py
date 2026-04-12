a,b,c,x,y = map(int,input().split())
money1=a*x+b*y
money2=a*(x-min(x,y))+b*(y-min(x,y))+c*2*min(x,y)
money3=max(x,y)*c*2
print(min(money1,money2,money3))