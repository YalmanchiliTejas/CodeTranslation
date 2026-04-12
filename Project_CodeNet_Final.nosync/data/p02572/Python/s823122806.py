D = int(1e9 + 7)
N = int(input())
M = [int(i) for i in input().split()]

R = sum(M[1:])

sum_ = 0
for i, x in enumerate(M[:-1]):
    sum_ += R * x
    sum_ %= D
    R -= M[i+1]

print(sum_)
