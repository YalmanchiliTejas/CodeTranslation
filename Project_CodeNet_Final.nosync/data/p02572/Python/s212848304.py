N = int(input())
A = list(map(int, input().split()))

tot = sum(A)
ans = 0
for a in A:
  ans += (tot - a) * a
print(ans//2%1000000007)