def cal(N, i):
    if N > 0:
        return 2 * cal(N - 1, i) + i
    elif N == 0:
        return 1
    else:
        return 0

def pCal(N ,X):
    total = cal(N, 3)
    half = total // 2
    pTmp = cal(N - 1, 1)
    if X == 1 and N == 0:
        return 1
    elif X <= N:
        return 0
    elif X < half:
        return pCal(N - 1, X - 1)
    elif X == half:
        return pTmp
    elif X == half + 1:
        return pTmp + 1
    elif total > X > half + 1:
        return (pTmp + 1) + pCal(N - 1, X - (half + 1))
    elif X == total:
        return cal(N, 1)
N, X = list(map(int, input().split()))
print(pCal(N, X))