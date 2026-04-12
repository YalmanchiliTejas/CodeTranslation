n=int(input())
h=list(map(int,input().split()))
cnt=0
a=0
for i in range(n):
  if h[i]>=a:
    a=h[i]
  if h[i]>=a:
    cnt+=1
print(cnt)