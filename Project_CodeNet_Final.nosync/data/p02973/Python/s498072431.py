import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

def LIS(A):
    """
    returns Longest Increasing Subsequence of list A.
    """
    B = [A[0]]
    for i in range(N-1):
        if A[i+1] >= B[-1]:
            B.append(A[i+1])
        else:
            index = bisect.bisect_left(B, A[i+1])
            B[index] = A[i+1]
    return B

def LDS(A):
    """
    returns Longest Decreasing Subsequence of list A.
    """
    A = A[::-1]
    B = [A[0]]
    for i in range(N-1):
        if A[i+1] >= B[-1]:
            B.append(A[i+1])
        else:
            index = bisect.bisect_right(B, A[i+1])
            B[index] = A[i+1]
    return B[::-1]


print(len(LDS(A)))