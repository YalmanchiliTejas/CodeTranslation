from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))


def solve():
    N, X, M = it()
    if N == 1:
        return X % M
    value = defaultdict(int)
    history = defaultdict(int)
    cur = 0
    cnt = 0
    for i in range(N):
        if X in history:
            break
        value[X] = cur
        history[X] = i
        cnt += 1
        cur += X
        X = X * X % M
    period = i - history[X]
    cur += (N - cnt) // period * (cur - value[X])
    for i in range((N - cnt) % period):
        cur += X
        X = X * X % M
    return cur

if __name__ == '__main__':
    print(solve())