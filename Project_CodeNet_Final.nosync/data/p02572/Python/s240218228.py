N = int(input())
A = list(map(int, input().split()))
tmp = sum(A)
sum_ = 0

for a in A:
    tmp -= a
    sum_ += a * tmp

print(sum_ % (1_000_000_007))
