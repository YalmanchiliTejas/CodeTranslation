# ABC054C - One-stroke Path
from itertools import permutations as perm


def main():
    N, M, *A = map(int, open(0).read().split())
    E = {(i, j) for i, j in zip(A[::2], A[1::2])}
    ans = 0
    for path in perm(range(2, N + 1), N - 1):  # check all possible paths (O(N!))
        path = (1,) + path
        if all((i, j) in E or (j, i) in E for i, j in zip(path, path[1:])):
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()