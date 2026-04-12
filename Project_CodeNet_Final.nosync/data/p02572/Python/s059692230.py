n = int(input())
x = list(map(int, input().strip().split()))
sum=0
minsum=0
for i in range(0,n):
    minsum += x[i]
for i in range(0,n-1):
    minsum-=x[i]
    sum += x[i]*minsum
    if(sum>10**9+7):
        sum%=(10**9+7)
print(sum)