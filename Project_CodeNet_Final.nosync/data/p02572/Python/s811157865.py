def main():
    n = int(input())
    a_list = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    sum_a = sum(a_list)
    ans = 0

    for i in range(n - 1):
        sum_a -= a_list[i]
        ans += (a_list[i] * sum_a) % mod

    print(ans % mod)


if __name__ == "__main__":
    main()
