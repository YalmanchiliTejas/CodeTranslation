from sys import stdin


def dfs(e, ans, done, N, graph):
    if (1 << N) - 1 == done:
        ans += 1
        return ans
    for s in graph[e]:
        if done >> s & 1:
            continue
        done ^= 1 << s
        ans = dfs(s, ans, done, N, graph)
        done ^= 1 << s
    return ans


def main():
    lines = stdin.readlines()
    N, M = map(int, lines[0].split())
    graph = [[] for i in range(N)]
    for i in range(1, M + 1):
        a, b = map(lambda x: int(x) - 1, lines[i].split())
        # 0-based indexing
        graph[a].append(b)
        graph[b].append(a)
    ans = 0
    print(dfs(0, ans, 1, N, graph))
    return


main()
