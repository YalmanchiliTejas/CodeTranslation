N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
a1, b1 = A[:N//2], sorted(A[N//2:], reverse=True)
a2, b2 = A[:N//2+1], sorted(A[N//2+1:], reverse=True)

cand1 = 2 * sum(b1[:len(a1) - 1]) + sum(b1[len(a1) - 1:]) - (2 * sum(a1[:len(b1) - 1]) + sum(a1[len(b1) - 1:]))
cand2 = 2 * sum(b2[:len(a2) - 1]) + sum(b2[len(a2) - 1:]) - (2 * sum(a2[:len(b2) - 1]) + sum(a2[len(b2) - 1:]))
print(max(cand1, cand2))