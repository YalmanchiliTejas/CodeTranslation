n=int(input())
l=list(map(int, input().split()))
c=1
m=l.pop(0)
for e in l:
  if e>=m:
    c+=1
    m=e
print(c)