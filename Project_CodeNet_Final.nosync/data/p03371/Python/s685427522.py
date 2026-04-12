
a,b,c,x,y=map(int,input().split())
money1=a*x+b*y
money2=min(min(x,y)*2*c+a*(x-min(x,y))+b*(y-min(x,y)),max(x,y)*2*c)
print(min(money1,money2))