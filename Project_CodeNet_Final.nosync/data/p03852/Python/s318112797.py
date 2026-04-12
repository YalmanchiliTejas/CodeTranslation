import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    c = input()

    if c in "aiueo":
        print("vowel")
    else:
        print("consonant")


if __name__ == '__main__':
    main()
