def main():
    N, M = map(int, input().split())
    matrix = [[0] * N for _ in range(N)]

    for _ in range(M):
        a, b = map(int, input().split())
        matrix[a-1][b-1] = 1
        matrix[b-1][a-1] = 1

    def dfs(v, used):
        if False not in used:
            return 1

        ans = 0
        for i in range(N):
            if not matrix[v][i]:
                continue
            if used[i]:
                continue

            used[i] = True
            ans += dfs(i, used)
            used[i] = False

        return ans

    used = [False] * N
    used[0] = True

    print(dfs(0, used))


if __name__ == '__main__':
    main()
