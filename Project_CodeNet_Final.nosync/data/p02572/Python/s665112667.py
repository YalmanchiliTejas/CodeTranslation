M = 10**9+7

N, A = int(input()), list(map(int, input().split()))

sum_A = list()

sum_val = 0

for idx in range(len(A)-1, -1, -1):
    sum_val += A[idx]
    sum_A.append(sum_val)

sum_A.reverse()

ret = 0

for idx in range(0, len(A)):
    ret += A[idx]*(sum_A[idx] - A[idx])
    ret %= M

print('{}'.format(ret))
