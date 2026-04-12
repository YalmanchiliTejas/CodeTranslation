def calc_score(li):
    prev = li[0]
    ret = 0
    for el in li:
        ret += abs(el - prev)
        prev = el
    return ret


N, *A = map(int, open(0).read().split())
A = sorted(A)
if N % 2:
    ans = 0
    li = [0] * N
    li[0] = A[N // 2]
    for i in range(N // 2):
        li[i * 2 + 1] = A[i + N // 2 + 1]
        li[i * 2 + 2] = A[i]
    ans = calc_score(li)
    li[N - 1] = A[N // 2]
    for i in range(N // 2):
        li[i * 2] = A[i + N // 2 + 1]
        li[i * 2 + 1] = A[i]
    print(max(ans, calc_score(li)))
else:
    li = [0] * N
    for i in range(N // 2):
        li[i * 2] = A[i + N // 2]
        li[i * 2 + 1] = A[i]
    print(calc_score(li))
