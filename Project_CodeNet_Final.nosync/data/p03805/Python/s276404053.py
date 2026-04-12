import itertools


def main():
    n, m = [int(i) for i in input().split()]
    path_matrix = [[False] * n for _ in range(n)]
    for _ in range(m):
        a, b = [int(i) for i in input().split()]
        a -= 1
        b -= 1
        path_matrix[a][b] = True
        path_matrix[b][a] = True

    ans = 0
    for path in itertools.permutations(range(n), n):
        if path[0] != 0:
            continue
        for i in range(n):
            if i == n - 1:
                ans += 1
                break
            if not path_matrix[path[i]][path[i+1]]:
                break

    print(ans)


if __name__ == "__main__":
    main()