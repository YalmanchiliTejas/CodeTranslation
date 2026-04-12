N,X,M = map(int, input().split())
A = [X]
S = set(A)
cnt = 0
i = 0
for i in range(1, N):
    A.append(A[i-1] ** 2 % M)
    if A[i] in S:
        break
    else:
        S.add(A[i])
roup_cycle = i - A.index(A[i])
before_roup_sums = sum(A[:A.index(A[i])])
roup_sums = sum(A[A.index(A[i]):i])

if roup_cycle != 0:
    roup_amount = (N - A.index(A[i])) // roup_cycle
    roup_mod = (N - A.index(A[i])) % roup_cycle
    print(before_roup_sums + roup_sums * roup_amount + sum(A[A.index(A[i]):(A.index(A[i]) + roup_mod)]))
else:
    print(sum(A))