def main():
    n = int(input())
    a_list = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    x = 0
    ans = 0

    for i in range(1, n):
        x = (x + a_list[i - 1]) % mod
        ans = (ans + a_list[i] * x) % mod

    print(ans)


if __name__ == "__main__":
    main()
