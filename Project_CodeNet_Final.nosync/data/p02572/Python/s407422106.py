N = int(input())
arr1 = list(map(int,input().split()))
arr2 = [0 for _ in range(N)]
sum = 0
for i in range(N):
    arr2[i] = sum+arr1[i]
    sum = arr2[i]

k = 10**9+7

count = 0
for i in range(N-1):
    count += arr2[i]*arr1[i+1]
    count %= k

print(count)
