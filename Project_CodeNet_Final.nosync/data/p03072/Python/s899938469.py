def main():
    n = int(input())
    hh = list(map(int, input().split()))
    res = 0
    h_max = 0
    for h in hh:
        if h_max <= h:
            res += 1
            h_max = h
    print(res)


if __name__ == "__main__":
    main()
