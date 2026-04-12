n=int(input())
a=list(map(int,input().split(" ")))
max=a[0]
count=1
for i in range(1,n):
  if max<=a[i]:
    count+=1
    max=a[i]
print(count)