a,b,c,x,y=map(int,input().split())
r=min(a+b,c*2)*min(x,y)
print(r+min(a,2*c)*(x-y) if x>y else r+min(b,2*c)*(y-x))