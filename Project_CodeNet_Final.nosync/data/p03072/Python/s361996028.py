n=int(input())
h=list(map(int,input().split()))
c=1
if len(h)>1 and h[0]<=h[1]:
  c=2
for i in range(2,n):
  if h[i]>=max(h[0:i]):
    c+=1
print(c)