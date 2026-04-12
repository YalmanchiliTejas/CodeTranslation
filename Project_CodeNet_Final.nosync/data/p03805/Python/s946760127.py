# coding: utf-8

import itertools

def array2d(dim1, dim2, init=None):
    return [[init for _ in range(dim2)] for _ in range(dim1)]

II = lambda: int(input())
MI = lambda: map(int, input().split())
MIL = lambda: list(MI())
MIS = lambda: input().split()


def main():
    N, M = MI()
    nb = array2d(N, N, False)
    for i in range(M):
        a, b = MI()
        a -= 1
        b -= 1
        nb[a][b] = nb[b][a] = True
    cnt = 0
    for perm in itertools.permutations(range(1, N)):
        p = [0] + list(perm)
        cnt += all([nb[p[i-1]][p[i]] for i in range(1, N)])
    return cnt

if __name__ == "__main__":
    print(main())
