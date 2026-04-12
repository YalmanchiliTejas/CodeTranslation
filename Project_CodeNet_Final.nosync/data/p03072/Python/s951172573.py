def main():
    n = int(input())
    hs = list(map(int, input().split()))
    lower = float("-inf")
    ans = 0
    for h in hs:
        lower = max(lower, h)
        if lower <= h:
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()
