a,b,c,x,y=map(int,input().split())
m=min(a*x+b*y,2*c*max(x,y))
if x<y:x,y,a,b=y,x,b,a
print(min(m,2*c*y+(x-y)*a))