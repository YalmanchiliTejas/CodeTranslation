def abc177_c_2():
    n = int(input())
    a = list(map(int, input().split(' ')))

    mod = 10 ** 9 + 7
    ans = 0
    x = 0

    for i in range(n):
        ans = (ans + a[i] * x) % mod
        x = (x + a[i]) % mod

    print(ans)

if __name__ == '__main__':
    abc177_c_2()