a,b,c,x,y=map(int,input().split())

val=a*x+b*y
val2=2*c*x+b*(y-x) if y>x else 2*c*y+a*(x-y)
val3=2*c*max(x,y)
print(min(val,val2,val3))