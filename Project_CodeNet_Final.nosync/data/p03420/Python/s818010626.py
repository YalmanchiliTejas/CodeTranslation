def main():
    n, k = map(int, input().split())
    answer = 0
    for i in range(k + 1, n + 1):
        answer += (n // i) * (i - k)
        add = 1
        if k == 0:
            add = 0
        answer += max(n % i - k + add, 0)
    print(answer)


if __name__ == '__main__':
    main()

