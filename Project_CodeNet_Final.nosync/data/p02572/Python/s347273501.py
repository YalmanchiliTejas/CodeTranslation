N = int(input())
A = list(map(int, input().split()))
assert len(A) == N
total = 0
sum_A = sum(A)
for i,ai in enumerate(A):
  sum_A -= ai
  total += ai * sum_A
print(total % (10 ** 9 + 7))