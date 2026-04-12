import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    H, W = map(int, input().split())
    A = list(list(input()) for _ in range(H))

    res = []
    remove = 0
    for h in range(H):
        for w in range(W):
            if A[h][w] == "#":
                res.append(A[h])
                break
        else:
            remove += 1
    H -= remove

    res2 = [[] for _ in range(H)]
    for w in range(W):
        for h in range(H):
            if res[h][w] == "#":
                for i in range(H):
                    res2[i].append(res[i][w])
                break

    for i in res2:
        print("".join(i))


if __name__ == '__main__':
    resolve()
