import sys
from collections import Counter

stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

mod = 10 ** 9 + 7

c = input()
print("vowel" if c in ["a", "e", "i", "o", "u"] else "consonant")


