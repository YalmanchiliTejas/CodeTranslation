def main():
    N, K = map(int, input().split())
    cnt = 0
    for b in range(1,N+1):
        cnt += (N // b) * max(0, b - K)
        cnt += max(0, (N % b) + 1 - K)

    if K == 0:
        cnt -= N

    print(cnt)


if __name__ == "__main__":
    main()