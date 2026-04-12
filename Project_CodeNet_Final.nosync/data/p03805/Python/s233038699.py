from collections import defaultdict


def solve(N, ab, ne_table, start: int, used: set):
    if len(used) == N:
        return 1
    res = 0
    next_list = ne_table[start]
    for i in next_list:
        if i not in used:
            res += solve(N, ab, ne_table, i, used.union({i}))
    return res


def main():
    N, M = [int(a) for a in input().split()]

    ab = [
        [int(a) - 1 for a in input().split()]
        for _ in range(M)
    ]

    ne_table = defaultdict(lambda: [])
    for (a, b) in ab:
        ne_table[a].append(b)
        ne_table[b].append(a)

    print(solve(N, ab, ne_table, 0, {0}))


if __name__ == '__main__':
    main()
