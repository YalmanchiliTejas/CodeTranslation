def main():
    n = int(input())
    hs = map(int, input().rstrip().split(' '))
    highest = 0
    visible_count = 0
    for h in hs:
        if h >= highest:
            visible_count += 1
            highest = h
    print(visible_count)

if __name__ == '__main__':
    main()