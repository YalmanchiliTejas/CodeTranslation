n=int(input())
l=list(map(int,input().split()))
tmp=l[0]
count=0
for i in range(n):
  if l[i]>=tmp:
    count+=1
    tmp=l[i]
print(count)