a,b,c,x,y=map(int,input().split())
cost=[a*x+b*y,2*max(x,y)*c]
if x>y:
  cost.append(2*y*c+(x-y)*a)
else:
  cost.append(2*x*c+(y-x)*b)
print(min(cost))