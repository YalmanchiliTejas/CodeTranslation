N = int(input())
A = list(map(int,input().split()))
ans = 0
num = sum(A)
for i in range(N - 1):
  num -= A[i]
  ans += A[i] * num
print(ans % (10 ** 9 + 7))