import sys

input = sys.stdin.readline


def main():
    N = int(input())
    q, r = divmod(N, 15)
    x = 800 * N
    y = 200 * q
    print(x - y)


if __name__ == "__main__":
    main()
