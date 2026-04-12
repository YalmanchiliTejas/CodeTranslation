a,b,c,x,y = map(int,input().split())
p = a*(x-min(x,y)) if x > y else b*(y-min(x,y))

print(min((a+b)*min(x,y)+p,c*min(x,y)*2+p,c*max(x,y)*2))