from itertools import chain

N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

m = N // 2
L, R = A[:m], A[m:]

def sumOfDiff(A):
    """隣の要素との差の合計"""
    return sum(abs(a - b) for a, b in zip(A, A[1:]))

def merge(L, R):
    """[L[0], R[0], L[1], R[1], ...]"""
    return list(chain.from_iterable(zip(L, R)))

if N % 2 == 0:
    # Rの最小値とLの最大値を端に
    s = sumOfDiff(merge(R, L))
else:
    L.reverse()
    B1 = merge(L, R[1:]) + [R[0]]  # Lの最大値が端
    B2 = merge(R[1:], L) + [R[0]]  # Rの最小値が端
    s = max(sumOfDiff(B1), sumOfDiff(B2))

print(s)
