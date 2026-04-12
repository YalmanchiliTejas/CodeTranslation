N = int(input())
A = list(map(int, input().split()))

sumA = sum(A)

ans = 0
for a in A:
  sumA -= a
  ans += sumA * a

print(ans % 1000000007)