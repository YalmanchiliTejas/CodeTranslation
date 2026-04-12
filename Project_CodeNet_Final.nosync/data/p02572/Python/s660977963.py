MOD = 10**9 + 7
N = int(input())
arr = list(map(int, input().split()))
check = [0]*N
check[0] = arr[0]
check2 = [sum(arr)]*N
ans = 0
for i in range(N-1):
    check[i+1] = check[i]+arr[i+1]
for i in range(N):
    check2[i] -= check[i]
for i in range(N-1):
    ans += check2[i]*arr[i]
    ans %= MOD
print(ans)