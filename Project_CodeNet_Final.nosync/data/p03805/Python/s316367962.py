from sys import stdin
mat = [[False] * 8 for _ in range(8)]
def dfs(point, visited):
        all_visited = True
        n = len(visited)
        for i in range(n):
            if visited[i] == False:
                all_visited = False
        if all_visited:
            return 1
        ans = 0
        for i in range(n):
            # print("point", point, "i", i)
            # print(visited)
            if mat[point][i] == True and visited[i] ==False:
                # print("passed")
                visited[i] = True
                ans += dfs(i, visited)
                visited[i] = False
        return ans
def main():
    n, m = list(map(int, input().split()))
    
    for _ in range(m):
        a, b = list(map(int, input().split()))
        a = a - 1
        b = b - 1
        mat[a][b] = True
        mat[b][a] = True
    # print(mat)
    v = [False] * n
    v[0] = True
    print(dfs(0, v))

if __name__ == '__main__':
    main()