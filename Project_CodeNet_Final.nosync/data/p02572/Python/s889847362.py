MOD = 10**9 + 7
N = int(input())
arr = list(map(int, input().split()))
check = [sum(arr)]*N
ans = 0
tmp = 0
for i in range(N-1):
    tmp += arr[i]
    check[i] -= tmp
for i in range(N-1):
    ans += check[i]*arr[i]
    ans %= MOD
print(ans)