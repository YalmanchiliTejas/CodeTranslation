import collections
def main():

    N, M = map(int, input().split())
    graph = collections.defaultdict(list)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    # print(graph)

    cur = [[1, 1 << 1]]
    for _ in range(N-1):
        temp = []
        for a, h in cur:
            for b in graph[a]:
                if (h >> b) % 2 == 0:
                    temp.append([b, h | (1 << b)])
        cur = temp
        # print(cur)
    return len(cur)

if __name__ == '__main__':
    print(main())
