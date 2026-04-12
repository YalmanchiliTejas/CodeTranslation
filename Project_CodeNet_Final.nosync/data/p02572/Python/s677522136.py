import itertools


def main():
    count = 0
    MOD = 10**9+7
    n = int(input())
    a = list(map(int, input().split()))
    s = [0]
    for i in range(n-1):
        s.append((s[i]+a[i]) % MOD)
    for ai, si in zip(a, s):
        count += (ai*si) % MOD
    return count % MOD


if __name__ == "__main__":
    print(main())
