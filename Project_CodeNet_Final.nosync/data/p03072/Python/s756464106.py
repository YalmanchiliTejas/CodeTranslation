def main():
    N = int(input())
    H = [int(n) for n in input().split()]

    counter = 0
    for i, h in enumerate(H):
        canView = True
        for j in range(i):
            if H[j] > h:
                canView = False
        if canView:
            counter += 1

    print(counter)


if __name__ == '__main__':
    main()
