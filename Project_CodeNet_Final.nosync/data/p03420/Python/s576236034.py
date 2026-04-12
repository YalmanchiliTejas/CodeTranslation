def main():
    N, K = (int(i) for i in input().split())
    if K == 0:
        return print(N**2)
    ans = 0
    for b in range(2, N+1):
        if K > b-1:
            continue
        pat = N//b
        ans += pat*(b-K)
        m = N % b
        if K <= m:
            ans += m-K+1
    print(ans)


if __name__ == '__main__':
    main()
