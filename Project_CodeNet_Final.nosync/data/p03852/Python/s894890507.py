import sys
from math import sqrt
from collections import Counter

input = sys.stdin.readline


def I():
    return int(input())


def MI():
    return map(int, input().split())


def LI():
    return list(MI())


def LIN(n: int):
    return [I() for _ in range(n)]


inf = float("inf")
mod = 10 ** 9 + 7


def main():
    c = input().rstrip()

    if c == "a" or c == "e" or c == "i" or c == "o" or c == "u":
        print("vowel")
    else:
        print("consonant")

    pass


if __name__ == "__main__":
    main()
