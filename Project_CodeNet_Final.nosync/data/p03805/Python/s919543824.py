from itertools import permutations


def is_possible_case(per):
    prv_node = 0
    for node in per:
        if node not in g[prv_node]:
            return 0
        prv_node = node
    return 1


if __name__ == '__main__':
    N, M = map(int, input().split())
    g = {i: [] for i in range(N)}
    for _ in range(M):
        a, b = map(int, input().split())
        g[a - 1].append(b - 1)
        g[b - 1].append(a - 1)

    ans = 0
    for per in permutations([i for i in range(1, N)]):
        ans += is_possible_case(per)

    print(ans)
