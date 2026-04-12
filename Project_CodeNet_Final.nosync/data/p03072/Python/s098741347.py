n=int(input())
h=list(map(int,input().split()))
m,count=0,0
for i in range(n):
  m=max(m,h[i])
  if h[i]==m:
    count+=1
print(count)