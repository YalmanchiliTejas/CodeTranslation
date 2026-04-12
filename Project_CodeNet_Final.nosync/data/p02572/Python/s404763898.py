def main():
    n = int(input())
    a_list = list(map(int, input().split()))

    sum_list = [0 for _ in range(n)]
    sum_list[0] = sum(a_list)
    ans = 0

    for i in range(1, n):
        sum_list[i] = sum_list[i - 1] - a_list[i - 1]

    for i in range(n - 1):
        ans += a_list[i] * sum_list[i + 1] % (10 ** 9 + 7)

    print(ans % (10 ** 9 + 7))


if __name__ == "__main__":
    main()
