def main():
    N = int(input())
    H = list(map(int, input().split()))
    max_height = H[0]
    ans = 1

    for i in range(1, N):
        if H[i] >= max_height:
            ans += 1
            max_height = H[i]

    print(ans)


if __name__ == '__main__':
    main()