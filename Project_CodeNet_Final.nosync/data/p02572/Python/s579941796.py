N = int(input())
As = list(map(int, input().split()))
m = 10**9 + 7
result = 0
As_sum = sum(As)
for i in range(N-1):
  As_sum = As_sum - As[i]
  result += (As[i] * As_sum) % m

print(result % m)