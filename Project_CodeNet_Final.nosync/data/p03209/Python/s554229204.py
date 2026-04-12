def main():
    N, X = (int(i) for i in input().split())

    A = [1]
    B = [1]
    for i in range(N):
        A.append(2*A[-1]+3)
        B.append(2*B[-1]+1)

    def dfs(n, x):
        a = A[n]
        b = B[n-1]
        if n == 0:
            return 1
        elif n >= x:
            return 0
        elif x == a//2:
            return b
        elif x == a//2 + 1:
            return b + 1
        elif x < a//2:
            return dfs(n-1, x-1)
        elif x > a//2 + 1:
            return dfs(n-1, x-(a//2)-1) + (b + 1)

    print(dfs(N, X))


if __name__ == '__main__':
    main()
