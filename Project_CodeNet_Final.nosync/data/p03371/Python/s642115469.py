a,b,c,x,y= map(int, input().split(" "))

cost1=a*x+b*y
cost2=c*2*max(x,y)
if min(x,y)==x:
    cost3=min(x,y)*2*c+(y-x)*b
else:
    cost3=min(x,y)*2*c + (x-y)*a
    
print(min(cost1,cost2, cost3))
