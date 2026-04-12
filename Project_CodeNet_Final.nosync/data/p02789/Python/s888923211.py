from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n, m = map(int, input().split())
    print('Yes') if n == m else print('No')


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
