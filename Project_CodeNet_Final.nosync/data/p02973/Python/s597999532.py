import bisect
def LIS():
    L[0] = A[0]
    length = 1
    for i in range(1, N):
        if L[length-1] < A[i]:
            L[length] = A[i]
            length += 1
        else:
            j = bisect.bisect_left(L, A[i])
            L[min(length-1, j)] = A[i]
    return length

def LISDesc():
    L[0] = A[-1]
    length = 1
    for i in range(N-2, -1, -1):
        if L[length-1] <= A[i]:
            L[length] = A[i]
            length += 1
        else:
            j = bisect.bisect_right(L, A[i])
            L[min(length-1, j)] = A[i]
    return length

INFTY = 10**13
N = int(input())
A = [int(input()) for i in range(N)]
L = [INFTY for i in range(N)]
ans = LISDesc()
print(ans)
