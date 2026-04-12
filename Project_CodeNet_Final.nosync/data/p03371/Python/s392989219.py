a,b,c,x,y = map(int,input().split())

if x>=y:
    d = (x-y)*a
else:
    d = (y-x)*b
print(min(a*x +b*y,(max(x,y)*2*c),min(x,y)*2*c+d))