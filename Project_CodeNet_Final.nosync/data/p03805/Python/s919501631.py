# coding: utf-8


def solve(*args: str) -> str:
    n, m = map(int, args[0].split())
    edges = [set() for _ in range(n)]
    for AB in args[1:]:
        a, b = map(int, AB.split())
        edges[a-1].add(b-1)
        edges[b-1].add(a-1)

    count = 0
    stack = [(0, 0)]
    while stack:
        node, visited = stack.pop()
        visited |= 1 << node

        if visited+1 == 1 << n:
            count += 1

        for dist in edges[node]:
            if visited & (1 << dist) == 0:
                stack.append((dist, visited))

    return str(count)


if __name__ == "__main__":
    print(solve(*(open(0).read().splitlines())))
