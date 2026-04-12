N = int(input())
X = list(map(int, input().split()))
p = 0
s = sum(X)
for n in range(N):
  s -= X[n] 
  s = s % (10**9 + 7)
  p += s * X[n]
  p = p % (10**9 + 7)

print(p)