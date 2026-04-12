n=int(input())
h=list(map(int,input().split()))
m=h[0]
c=0
for i in range(n):
  if m<=h[i]:
    c+=1
    m=h[i]
print(c)

