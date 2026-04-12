a,b,c,x,y=map(int,input().split())
p=10**9
for i in range(max(x,y)+1):
  p=min(p,a*max(0,x-i)+b*max(0,y-i)+c*2*i)
print(p)