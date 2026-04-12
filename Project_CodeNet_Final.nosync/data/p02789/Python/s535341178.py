from sys import stdin


def main():
    n, m = map(int, stdin.readline().split())
    print('Yes') if n == m else print('No')


if __name__ == "__main__":
    main()
