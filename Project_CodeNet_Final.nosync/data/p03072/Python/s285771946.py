def main():

    N = int(input())

    H = [int(v) for v in input().split()]

    h = H[0]

    max_h = h

    count = 1
    for h in H[1:]:
        if h >= max_h:
            count += 1
        max_h = max(max_h, h)

    print(count)


if __name__ == "__main__":
    main()
