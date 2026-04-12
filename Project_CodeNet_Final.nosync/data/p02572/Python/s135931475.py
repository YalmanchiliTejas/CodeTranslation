N = int(input())
A = list(map(int, input().split()))

# こまめにmodを取る
mod = 10**9 + 7
s = 0
t = 0
for i in range(N):
    s += A[i]
    s %= mod
    t += (A[i]**2 % mod)
    t %= mod
s = s**2 % mod
ans = (s - t) % mod
# 割り算のmodを取るときは、逆元を求め掛け算に変換してmodを取る
ans = (ans * 500000004) % mod

print(ans)