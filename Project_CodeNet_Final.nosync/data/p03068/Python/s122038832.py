#!/snap/bin/pypy3

def main():
    N = int(input())
    S = input()
    K = int(input())

    char = S[K-1]

    for c in S:
        print(c if c == char else "*", sep='', end='')
    print('')


if __name__ == '__main__':
    main()
