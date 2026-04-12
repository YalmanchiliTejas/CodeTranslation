def main():
    n = int(input())
    h_list = list(map(int, input().split()))
    highest = 0
    cnt = 0

    for h in h_list:
        if highest <= h:
            highest = h
            cnt += 1

    print(cnt)


if __name__ == "__main__":
    main()
