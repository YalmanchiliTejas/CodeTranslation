def rec(digit, flag, k):
    limit = int(N[digit])
    if k > K:
        return 0
    if digit == len(N) - 1:
        if k == K:
            return 1
        elif k == K - 1:
            return limit if flag else 9
        else:
            return 0
    if flag:
        if limit == 0:
            return rec(digit + 1, 1, k)
        else:
            return rec(digit + 1, 0, k + 1) * (limit - 1) + rec(digit + 1, 1, k + 1) + rec(digit + 1, 0, k)
    else:
        return rec(digit + 1, 0, k + 1) * 9 + rec(digit + 1, 0, k)

N = input()
K = int(input())
print(rec(0, 1, 0))