def main():
    N = int(input())
    H = list(map(int, input().split()))
    ans = 1
    for i in range(1, N):
        k = True
        for j in range(i):
            if H[i] < H[j]:
                k = False
                break
        if k:
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()
