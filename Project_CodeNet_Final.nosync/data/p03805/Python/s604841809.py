from functools import lru_cache


N, M = map(int, input().split())
E = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    E[a-1].append(b-1)
    E[b-1].append(a-1)

S = 1
G = (1 << N) - 1


@lru_cache(2**N*N)
def is_visited(v, path):
    return path & (1 << v)


@lru_cache(2**N*N)
def count(u, path):
    if path == G:
        return 1

    return sum(
        count(v, path ^ (1 << v))
        for v in E[u]
        if not is_visited(v, path)
    )


print(count(0, S))
