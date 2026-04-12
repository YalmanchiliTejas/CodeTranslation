n = int(input())
#n, m = map(int, input().split())
al = list(map(int, input().split()))
#al=[list(input()) for i in range(n)]
mod = 10**9+7
add = 0
ans = 0
for i in range(n-1, 0, -1):
    add = (add+al[i]) % mod
    ans = (ans+add*al[i-1]) % mod

print(ans)
