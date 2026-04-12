n=int(input())
arr=list(map(int,input().split()))
count=1
tmp=arr[0]
for i in range(1,n):
  if tmp <= arr[i]:
    count+=1
    tmp=arr[i]
print(count)