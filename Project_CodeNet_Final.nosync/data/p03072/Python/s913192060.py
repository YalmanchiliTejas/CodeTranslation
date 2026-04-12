def main():
    n = int(input())
    h = [int(i) for i in input().split()]
    ans = 1
    for i in range(1, n):
        for j in range(i):
            if h[i] < h[j]:
                break
        else:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()