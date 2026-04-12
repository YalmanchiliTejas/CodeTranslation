a,b,c,x,y = map(int,input().split())
if x>y:
    s = c*y*2+(x-y)*a
else:
    s = c*x*2+(y-x)*b
print(min((a*x+b*y),(c*max(x,y)*2),s))
