a,b,c,x,y = map(int,input().split())
pizza = [(x,a),(y,b)]
pizza.sort()
sp,sq = pizza[0][1],pizza[0][0]
lp,lq = pizza[1][1],pizza[1][0]


print(min(a*x+b*y,c*2*lq,c*2*sq+lp*(lq-sq)))