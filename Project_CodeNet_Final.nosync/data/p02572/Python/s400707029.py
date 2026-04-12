N = input()
A = list(map(int, input().split()))

ans = sum(A)**2
for a in A:
  ans -= a*a
ans //= 2
print(ans%(10**9+7))
