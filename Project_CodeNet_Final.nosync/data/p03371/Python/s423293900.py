a,b,c,x,y = map(int,input().split())
d = ((x-y)*a if x >= y else (y-x)*b)
print(min(a*x +b*y,(max(x,y)*2*c),min(x,y)*2*c+d))