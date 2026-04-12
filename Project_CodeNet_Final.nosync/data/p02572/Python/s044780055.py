LI = lambda: list(map(int, input().split()))

N = int(input())
A = LI()

MOD = 10 ** 9 + 7


def modinv(x):
    return pow(x, MOD - 2, MOD)


def main():
    s = sum(A) % MOD
    ans = s * s % MOD
    for a in A:
        ans = (ans - a ** 2) % MOD
    ans = ans * modinv(2) % MOD
    print(ans)


if __name__ == "__main__":
    main()
