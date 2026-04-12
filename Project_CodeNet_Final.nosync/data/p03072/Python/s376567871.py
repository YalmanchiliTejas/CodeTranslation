def main():
    N = int(input())
    H = list(map(int, input().split()))

    cnt = 1
    tmp = H[0]
    for i in range(1,N):
        if H[i] >= tmp:
            cnt += 1
            tmp = H[i]

    print(cnt)


main()