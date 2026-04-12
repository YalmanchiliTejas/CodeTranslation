import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    c = readline().strip()

    if c in 'aeiou':
        print('vowel')
    else:
        print('consonant')

    return


if __name__ == '__main__':
    main()
