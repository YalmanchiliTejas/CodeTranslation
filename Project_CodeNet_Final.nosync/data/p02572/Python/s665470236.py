import sys

MOD = 10 ** 9 + 7


def main():
    input = sys.stdin.buffer.readline
    n = int(input())
    a = list(map(int, input().split()))
    ans = sum(a) ** 2
    for e in a:
        ans -= e ** 2
    ans //= 2
    ans %= MOD
    print(ans)


if __name__ == "__main__":
    main()
