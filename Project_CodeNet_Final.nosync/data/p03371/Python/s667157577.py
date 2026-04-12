a,b,c,x,y = map(int, input().split())
print(min(x*a+y*b,x*2*c+max(0,y-x)*b,y*2*c+max(0,x-y)*a))