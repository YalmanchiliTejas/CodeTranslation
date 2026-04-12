# import sys
# readline = sys.stdin.readline
# generator = (readline().strip() for _ in range(N))

# N, M = map(int, input().split())
# As = list(map(int, input().split()))
# queries = (input() for _ in range(N))


def solve():
    n = int(input())
    As = list(map(int, input().split()))

    mod = 10**9+7
    sums = [0] * (n+1)

    tmp = 0
    for i, a in enumerate(As[::-1]):
        tmp += a
        tmp %= mod
        sums[-i-1] = tmp

    total = 0
    for i, a in enumerate(As[:-1]):
        total += a * (sums[i+2])
        total %= mod

    return total


def main():
    print(solve())


if __name__ == "__main__":
    main()
