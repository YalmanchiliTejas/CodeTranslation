import sys
from sys import stdin


def input(): return stdin.readline().rstrip()


def mips():
    return map(int, input().split())


def ii():
    return int(input())
A, B, C, X, Y = mips()
money = 0
while X > 0 and Y > 0:
    if (A+B) <= 2*C:
        money += (A+B)
        X -= 1
        Y -= 1
    else:
        money += 2*C
        X -= 1
        Y -= 1
while X > 0:
    if A <= 2*C:
        money += A
        X -= 1
    else:
        money += 2*C
        X -= 1
        Y -= 1
while Y > 0:
    if B <= 2*C:
        money += B
        Y -= 1
    else:
        money += 2*C
        X -= 1
        Y -= 1
print(money)