N = int(input())
*A, = map(int, input().split())
ans = (sum(A)**2 - sum(a*a for a in A))//2
mod = 10**9 + 7

print(ans % mod)