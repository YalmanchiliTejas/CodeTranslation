n=int(input())
l=list(map(int,input().split()))
total=1
for i in range(1,n):
  if max(l[0:i])<=l[i]:
    total+=1
print(total)