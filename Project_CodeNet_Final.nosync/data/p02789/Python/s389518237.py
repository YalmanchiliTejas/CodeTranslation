from sys import stdin


def main():
    N, M = [int(x) for x in stdin.readline().rstrip().split()]
    print('Yes' if N == M else 'No')


if __name__ == "__main__":
    main()
