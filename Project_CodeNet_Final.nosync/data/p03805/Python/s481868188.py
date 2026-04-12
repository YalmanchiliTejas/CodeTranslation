from itertools import permutations


def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(lambda x: int(x) - 1, input().split())
        graph[a].append(b)
        graph[b].append(a)
    answer = 0
    for p in permutations([i for i in range(n)]):
        if p[0] != 0:
            continue
        if all(p[i] in graph[p[i - 1]] for i in range(1, n)):
            answer += 1
    print(answer)


if __name__ == '__main__':
    main()

