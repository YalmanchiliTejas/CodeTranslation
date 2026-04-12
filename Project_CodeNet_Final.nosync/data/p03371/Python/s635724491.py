a,b,c,x,y=map(int,input().split())
if x>y:
    z=a 
else:
    z=b 
print(min(min(x,y)*2*c + z*abs(x-y),a*x+b*y, max(x,y)*2*c))