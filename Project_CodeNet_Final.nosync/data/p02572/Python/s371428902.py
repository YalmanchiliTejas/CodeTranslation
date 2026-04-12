N = int(input())
A = list(map(int, input().split()))

B = A[-1]
ans = 0
for ai in A[-2::-1]:
  ans += (ai*B)%(10**9+7)
  B = (B+ai)%(10**9+7)

print(ans%(10**9+7))