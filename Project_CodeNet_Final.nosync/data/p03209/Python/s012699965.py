def main():
    N, X = (int(i) for i in input().split())
    ans = 0

    def dfs(n, x, ans):
        a = 1 + 4*(2**(n-1) - 1)
        if n == 1:
            return 1
        elif (n-1) >= x:
            return 0
        elif x == a//2:
            return 1 + 2*(2**(n-2) - 1)
        elif x == a//2 + 1:
            return 1 + 2*(2**(n-2) - 1) + 1
        elif x < a//2:
            ans += dfs(n-1, x-1, ans)
        elif x > a//2 + 1:
            ans += dfs(n-1, x-(a//2)-1, ans) + (1 + 2*(2**(n-2) - 1) + 1)
        return ans

    print(dfs(N+1, X, ans))


if __name__ == '__main__':
    main()
