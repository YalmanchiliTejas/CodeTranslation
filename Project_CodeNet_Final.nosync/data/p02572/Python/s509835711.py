MOD = 10**9 + 7
N = int(input())
arr = list(map(int, input().split()))
arr_sum = sum(arr)
arr2 = [0]*N
for i in range(N):
    arr2[i] = arr_sum - arr[i]
ans = 0
for i in range(N):
    ans += arr2[i]*arr[i]
print((ans//2)%MOD)