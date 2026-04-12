def main():
    n = int(input())
    H = list(map(int,input().split()))

    count = 0
    maximum = 0
    for i in range(n):
        if H[i] >= maximum:
            maximum = max(maximum,H[i])
            count += 1
    print(count)


if __name__ == '__main__':
    main()
