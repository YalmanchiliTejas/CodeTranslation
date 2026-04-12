n=int(input())
a=list(map(int,input().split()))
count=0
for i in range(n):
  if max(a[0:i]+[0])<=a[i]:
    count+=1
print(count)