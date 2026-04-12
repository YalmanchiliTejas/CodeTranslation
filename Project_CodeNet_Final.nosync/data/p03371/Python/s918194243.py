a,b,c,x,y = map(int,input().split())
plan1 = a*x+b*y
plan2 = c*max(x,y)*2
plan3 = c*x*2+b*(y-x) if x<y else c*y*2+a*(x-y)
print(min(plan1,plan2,plan3))