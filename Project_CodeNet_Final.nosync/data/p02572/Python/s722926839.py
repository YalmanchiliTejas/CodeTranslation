N = int(input())
A = list(map(int, input().split()))
 
s, t = 0, 0
for i in range(N):
  s += A[i]
  t += A[i]**2
s = s**2

# 割り算のmodを求めるため、逆元を求め、積に変換する
ans = (s-t) % (10**9+7)
# tmp = (2**1000000005) % (10**9+7)
tmp = 500000004
ans = (ans*tmp) % (10**9+7)
print(ans)