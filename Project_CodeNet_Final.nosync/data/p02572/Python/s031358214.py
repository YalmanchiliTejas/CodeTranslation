n=int(input())
lst=list(map(int,input().split()))
total=0
temp=0
for i in range(1, n):
  temp+=lst[i]
for j in range(n-1):
  total+=lst[j]*temp
  temp-=lst[j+1]
print(total%(10**9+7))