from sys import stdin


def main():
    S = stdin.readline().rstrip()
    if S == 'AAA' or S == 'BBB':
        print('No')
    else:
        print('Yes')


if __name__ == "__main__":
    main()
