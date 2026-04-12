import sys

INPUT = lambda: sys.stdin.readline().rstrip()
MAP = lambda: map(int, INPUT().split())

sys.setrecursionlimit(10 ** 9)


def main():
    H, W = MAP()
    A = [INPUT() for _ in range(H)]

    ans_H = []
    for y in range(H):
        for x in range(W):
            if A[y][x] == '#':
                ans_H.append(y)
                break

    ans_W = []
    for x in range(W):
        for y in range(H):
            if A[y][x] == '#':
                ans_W.append(x)
                break

    ans = ["" for _ in range(len(ans_H))]
    for i, h in enumerate(ans_H):
        for w in ans_W: ans[i] += A[h][w]

    for a in ans: print(a)


if __name__ == '__main__':
    main()