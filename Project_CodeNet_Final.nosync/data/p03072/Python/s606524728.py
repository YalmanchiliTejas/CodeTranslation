n=int(input())
l=list(map(int,input().split()))
mx=l[0]
c=1
for x in l[1:]:
  if x>=mx:
    c+=1
    mx=x
print(c)