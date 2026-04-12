N, X, M = [int(x) for x in input().split()]

A = [0] * (M + 1)
firstApearAt = {i:0 for i in range(M)}
A[1] =  X
firstApearAt[X] = 1
l, r = 1, 2
for i in range(2, M + 1):
    A[i] = (A[i - 1] * A[i - 1]) % M
    if firstApearAt[A[i]] > 0:
        r = i
        l = firstApearAt[A[i]]
        break
    firstApearAt[A[i]] = i

ans = 0
if N <= l - 1:
    ans = sum(A[1:N + 1])
else:
    q, p = (N - l + 1) // (r - l), (N - l + 1) % (r - l)
    ans = sum(A[1:l]) + q * sum(A[l:r]) + sum(A[l:l + p])

print(ans)