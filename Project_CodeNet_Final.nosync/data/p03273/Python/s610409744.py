import sys
input = sys.stdin.readline


def read():
    H, W = map(int, input().strip().split())
    A = []
    for i in range(H):
        a = list(input().strip())
        A.append(a)
    return H, W, A


def solve(H, W, A):
    is_skip_rows = [True for i in range(H)]
    is_skip_cols = [True for j in range(W)]
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                is_skip_rows[i] = False
                is_skip_cols[j] = False
    for i in range(H):
        if is_skip_rows[i]:
            continue
        line = []
        for j in range(W):
            if is_skip_cols[j]:
                continue
            line.append(A[i][j])
        print(''.join(line))


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
