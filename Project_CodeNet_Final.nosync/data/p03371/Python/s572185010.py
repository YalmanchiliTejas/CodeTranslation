a,b,c,x,y=map(int,input().split())
ret=float('inf')
for i in range(max(x,y)+1):
  ret=min(ret,i*c*2+max((x-i),0)*a+max((y-i),0)*b)
print(ret)