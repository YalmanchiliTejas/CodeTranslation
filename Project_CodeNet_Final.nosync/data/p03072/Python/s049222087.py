def main():
    n = int(input())
    hs = [int(x) for x in input().split()]
    count = 0
    for i in range(n):
        if i == 0:
            count += 1
        elif max(hs[:i]) <= hs[i]:
            count += 1
    print(count)

if __name__ == '__main__':
    main()
