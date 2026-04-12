a,b,c,x,y = map(int,input().split())
print(min(a*x+b*y,2*c*min(x,y)+abs(x-y)*(a if max(x,y)==x else b),2*c*min(x,y)+abs(x-y)*2*c))