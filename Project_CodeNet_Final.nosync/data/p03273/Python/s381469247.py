import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    H, W = map(int, input().split())
    A = [list(input()) for _ in range(H)]

    res = []
    for h in range(H):
        for w in range(W):
            if A[h][w] == "#":
                res.append(A[h])
                break

    res2 = [[] for _ in range(len(res))]
    for w in range(W):
        for h in range(len(res)):
            if res[h][w] == "#":
                for k in range(len(res)):
                    res2[k].append(res[k][w])
                break

    for i in res2:
        print("".join(i))


if __name__ == '__main__':
    resolve()
