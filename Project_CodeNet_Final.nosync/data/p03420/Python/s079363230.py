def main():
    n, k = map(int, input().split())

    cnt = 0
    for b in range(k+1, n+1):
        p = n // b + 1
        cnt += p * (b-k)

        if p * b > n + 1:
            cnt -= p * b - max((p-1)*b+k, n+1)

        if k == 0:
            cnt -= 1

    print(cnt)


if __name__ == '__main__':
    main()
