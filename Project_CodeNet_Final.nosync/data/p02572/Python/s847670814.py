def main():
    input()
    mod = 10**9 + 7
    arr = sorted(map(int, input().split()))
    arr.reverse()

    sm = arr[0] + arr[1]
    ans = arr[0] * arr[1] % mod

    for x in range(2, len(arr)):
        ans += sm * arr[x]
        sm += arr[x]

    print(ans % mod)


if __name__ == '__main__':
    main()