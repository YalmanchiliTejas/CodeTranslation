def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    ans = 0
    suma = a[-1]
    for i in range(n - 2, -1, -1):
        ans += a[i] * suma
        suma = (suma + a[i]) % mod
    print(ans % mod)


if __name__ == '__main__':
    resolve()
