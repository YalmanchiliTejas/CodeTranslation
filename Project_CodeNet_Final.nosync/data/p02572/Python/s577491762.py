N = int(input())
A = list(map(int, input().split(' ')))

mod = 10 ** 9 +7
amount = sum(A)
calc = []
for i in range(N - 1):
  amount = amount - A[i]
  calc.append(amount)

for i in range(N - 1):
  calc[i] *= A[i]

print(sum(calc) % mod)