
def resolve():
    N, X, M = map(int, input().split())

    cycle = [False] * M
    A = []
    for i in range(N):
        if cycle[X]:
            break
        cycle[X] = True
        A.append(X)
        X = X ** 2 % M

    # サイクルのスタートを探索
    loop_start = 0
    for i in range(len(A)):
        if A[i] == X:
            loop_start = i
            break

    # サイクル前の和
    ans = sum(A[:loop_start])
    N -= loop_start

    # サイクルの要素
    A = A[loop_start:]

    loops = N // len(A)
    rest = N % len(A)
    
    ans += sum(A) * loops + sum(A[:rest])

    print(ans)


if __name__ == "__main__":
    resolve()