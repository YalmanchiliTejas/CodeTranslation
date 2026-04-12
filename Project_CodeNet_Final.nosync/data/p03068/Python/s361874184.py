from sys import stdin


def main():
    _ = int(stdin.readline().rstrip())
    S = stdin.readline().rstrip()
    K = int(stdin.readline().rstrip())
    print(''.join([c if c == S[K - 1] else '*' for c in S]))


if __name__ == "__main__":
    main()
