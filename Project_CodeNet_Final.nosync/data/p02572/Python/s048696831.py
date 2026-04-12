def main():
    N = int(input())
    A_list = list(map(int, input().split()))
    mod = 10**9 + 7

    ans = 0
    A_ = sum(A_list) % mod
    for i in range(N-1):
        A = A_list[i]
        A_ = A_ - A
        ans = (ans + (A * A_) % mod) % mod
    print(ans)
    return


if __name__ == '__main__':
    main()
    