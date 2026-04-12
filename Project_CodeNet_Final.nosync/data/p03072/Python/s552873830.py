n=int(input())
a=list(map(int,input().split()))
sum=1
temp=a[0]
for i in range(n-1):
  if temp<=a[i+1]:
    temp=a[i+1]
    sum+=1
print(sum)