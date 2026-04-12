def main():
    n, k = map(int, input().split())
    answer = 0
    for i in range(1, n + 1):
        answer += max(0, i - k) * (n // i) + max(0, n % i - k + 1)
    print(answer if k > 0 else n ** 2)


if __name__ == '__main__':
    main()

