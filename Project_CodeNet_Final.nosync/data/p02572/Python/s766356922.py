n = int(input())
arr = [int(x) for x in input().split()]
arr.insert(0,0)
prefix = [0 for x in range(n+1)]
for i in range(1,n+1):
    prefix[i] = prefix[i-1]+arr[i];

ans = 0
mod = int(1e9+7)
for i in range(1,n):
    ans += arr[i]*(prefix[n]-prefix[i])
print(ans%mod)