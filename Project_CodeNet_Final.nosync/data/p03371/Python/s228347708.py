a,b,c,x,y = map(int, input().split())
d = (a if x > y else b)
print(min(a*x + b*y,min(x,y)*2*c + d*abs(x-y),max(x,y)*2*c))