from itertools import permutations


def main():
    n, m = map(int, input().split())

    path = [[False for _ in range(n)] for _ in range(n)]

    for i in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        path[a][b] = True
        path[b][a] = True

    res = 0
    perms = list(permutations(list(range(1, n)), n - 1))
    for p in perms:
        visited = 1
        prev = 0
        for now in p:
            if path[prev][now]:
                visited += 1
                prev = now
            else:
                break
        if visited == n:
            res += 1

    print(res)


if __name__ == '__main__':
    main()
