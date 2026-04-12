N = int(input())
A = [-1*int(input()) for _ in range(N)]


def LIS(seq: list) -> int:
    """param: seq
    return:LISの長さ（a_i =< a_j）
    """
    from bisect import bisect_right
    N = len(seq)
    L = [seq[0]]
    for i in range(1, N):
        if seq[i] > L[-1]:
            L.append(seq[i])
        else:
            idx = bisect_right(L, seq[i])
            if idx == len(L):
                L.append(None)  # avoid Out-of-Index-Error
            L[idx] = seq[i]
    return len(L)


print(LIS(A))
