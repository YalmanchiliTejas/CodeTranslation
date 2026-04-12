def main():
    N = int(input())
    H = list(map(int, input().split()))

    max_height = H[0]
    count = 0
    for h in H:
        if max_height <= h:
            count += 1
            max_height = h
    print(count)

if __name__ == '__main__':
    main()