from collections import defaultdict, Counter
from heapq import heapify, heappop, heappush
from sys import stdin


def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    if n % 2 == 0:
        if n == 2:
            print(max(a))
            return
        v = [[None for j in range(2)] for i in range(n)]
        v[0][0] = a[0]
        v[1][1] = a[1]
        for i in range(2, n):
            for j in range(2):
                c = []
                if v[i-2][j] is not None:
                    c.append(v[i-2][j])
                if j >= 1 and i >= 3:
                    if v[i-3][j-1] is not None:
                        c.append(v[i-3][j-1])
                if len(c) == 0:
                    continue
                v[i][j] = max(c) + a[i]
        c = [v[n-1][j] for j in range(2) if v[n-1][j] is not None]
        print(max(c))
    else:
        if n == 3:
            print(max(a))
            return
        v = [[None for j in range(3)] for i in range(n)]
        v[0][0] = a[0]
        v[1][1] = a[1]
        v[2][0] = a[0]+a[2]
        v[2][2] = a[2]
        for i in range(3, n):
            for j in range(3):
                c = []
                if v[i-2][j] is not None:
                    c.append(v[i-2][j])
                if j >= 1:
                    if v[i-3][j-1] is not None:
                        c.append(v[i-3][j-1])
                if j >= 2 and i >= 4:
                    if v[i-4][j-2] is not None:
                        c.append(v[i-4][j-2])
                if len(c) == 0:
                    continue
                v[i][j] = max(c) + a[i]
        c = [v[n-1][j] for j in range(1, 3) if v[n-1][j] is not None]
        print(max(c))


def input(): return stdin.readline().rstrip()


main()
