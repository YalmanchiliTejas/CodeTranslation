
import collections
from functools import lru_cache


def read():
    return input().strip()


def readInt():
    return int(input().strip())


def readList():
    return list(map(int, input().strip().split()))


x = readInt()

if x >= 30:
    print("Yes")
else:
    print("No")
