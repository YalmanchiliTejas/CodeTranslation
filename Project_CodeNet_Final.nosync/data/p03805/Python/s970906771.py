from collections import defaultdict


def c():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    stack = []
    count = 0

    stack.append((1, set()))

    while stack:
        val, visited = stack.pop()
        visited.add(val)
        if len(visited) == n:
            count += 1
            continue

        for g in graph[val]:
            if g not in visited:
                stack.append((g, set(visited)))

    print(count)


if __name__ == '__main__':
    c()
