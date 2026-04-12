n = int(input())
arr = list(map(int,input().split()))
result = 0
sum = arr[0]
for i in range(1,len(arr)):
    result += (sum*arr[i])
    sum+=arr[i]
print(result%1000000007)
