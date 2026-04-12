N = int(input())
A = [int(input()) for i in range(N)]

A_ = sorted(A)
A_r = list(reversed(A_))

n = (A_[0], A_r[0])
sum = abs(n[0] - n[1])
for i, (x, y) in enumerate(zip(A_[1:N//2], A_r[1:N//2])):
    sum += abs(n[0] - y) + abs(n[1] - x)
    n = (x, y)

if N%2 != 0:
    m = A_[N//2]
    sum += max(abs(n[0] - m), abs(n[1] - m))

print(sum)
