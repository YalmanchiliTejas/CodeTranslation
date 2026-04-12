def main():
    N, K = (int(i) for i in input().split())
    if K == 0:
        return print(N**2)
    ans = 0
    for b in range(K+1, N+1):
        ans += (b - K) * (N//b)
        if K <= N % b:
            ans += (N % b) - K + 1
    print(ans)


if __name__ == '__main__':
    main()
