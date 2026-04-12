a,b,c,x,y=map(int,input().split())
print(min(x*a+y*b,2*x*c+b*max(0,y-x),2*y*c+a*max(0,x-y)))