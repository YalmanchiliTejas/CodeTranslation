# ABC054C - One-stroke Path
# an undirected unweighted graph is given
# -> count up paths which visit all the vertices exactly once
# exhaustive search
from itertools import permutations as perm


def main():
    N, M = tuple(map(int, input().split()))
    E = set(tuple(map(int, input().split())) for _ in range(M))  # edges
    E |= {(j, i) for i, j in E}  # undirected graph -> add reversed paths
    ans = 0
    for path in perm(range(2, N + 1), N - 1):  # check all possible paths (O(N!))
        path = (1,) + path
        if all((i, j) in E for i, j in zip(path, path[1:])):
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()