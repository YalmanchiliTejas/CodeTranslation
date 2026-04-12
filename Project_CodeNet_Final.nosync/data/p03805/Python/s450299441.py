import collections
def main():
    N, M = map(int, input().split())
    graph = collections.defaultdict(list)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    cur = [[1, set([1])]]
    for _ in range(N-1):
        temp = []
        for a, visited in cur:
            for b in graph[a]:
                if b not in visited:
                    temp.append([b, visited | {b}])
        cur = temp
    return len(cur)


if __name__ == '__main__':
    print(main())