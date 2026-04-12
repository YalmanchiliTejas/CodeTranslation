N = int(input())
*A, = map(int, input().split())
mod = 10**9 + 7

s = sum(A)
ans = s*s - sum(a*a for a in A)
print(ans // 2 % mod)
