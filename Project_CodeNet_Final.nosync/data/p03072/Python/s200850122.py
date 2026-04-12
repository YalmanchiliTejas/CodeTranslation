def main():
    N = int(input())
    H = list(map(int, input().split()))
    max_h = 0
    ans = 0
    for h in H:
        if h >= max_h:
            ans += 1
            max_h = h
    print(ans)


if __name__ == '__main__':
    main()
