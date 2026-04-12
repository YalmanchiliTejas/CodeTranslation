a,b,c,x,y=map(int,input().split())
s=0
c*=2
if(x>y):
    s=min((a*x+b*y),((x-y)*a+y*c),c*max(x,y))
else:
    s=min((a*x+b*y),((y-x)*b+x*c),c*max(x,y))
print(s)