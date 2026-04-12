a,b,c,x,y=map(int,input().split())
c=c*2
print(min(c*max(x,y),y*c+max(x-y,0)*a,x*c+max(y-x,0)*b,a*x+b*y))