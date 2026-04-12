# ABC054C - One-stroke Path
# graph theory
# an undirected unweighted graph is given
# -> count up paths which visit all the vertices exactly once
import sys
input = sys.stdin.readline

from itertools import permutations as perm


def main():
    N, M = tuple(map(int, input().split()))
    A = set(tuple(map(int, input().split())) for _ in range(M))
    ans = 0
    for path in perm(range(2, N + 1), N - 1):  # check all possible paths (O(N!))
        path = (1,) + path
        if all((i, j) in A or (j, i) in A for i, j in zip(path, path[1:])):
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()