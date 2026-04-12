def main():
    N = int(input())
    H = list(map(int, input().split(" ")))
    max = -1
    result = 0
    for h in H:
        if h >= max:
            result += 1
            max = h
    print(result)


if __name__ == '__main__':
    main()