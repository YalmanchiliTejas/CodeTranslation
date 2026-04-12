n = int(input())
arr = list(map(int,input().split()))
mod = 10**9 + 7
som = sum(arr)
ans = 0
for i in range(n):
    ans+=(som-arr[i])*arr[i]
print((ans//2)%mod)