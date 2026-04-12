input().split()
h=list(map(int,input().split()))
r=1
m=h[0]
for i in h[1:]:
  if i >= m:
    r+=1
    m=i
print(r)