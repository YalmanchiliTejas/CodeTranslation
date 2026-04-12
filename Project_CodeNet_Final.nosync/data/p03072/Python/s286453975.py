n=int(input())
h=list(map(int,input().split()))
x=1
m=h[0]
for i in range(1,n):
  if h[i]>=m:
    x+=1
    m=h[i]
print(x)