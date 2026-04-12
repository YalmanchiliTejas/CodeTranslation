def main() -> None:
    N = int(input())
    H = [int(i) for i in input().split()]
    m = H[0]
    t = []
    ans = 0
    for i in range(0, len(H)):
        t.append(H[i])
        if max(t) <= H[i]:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
