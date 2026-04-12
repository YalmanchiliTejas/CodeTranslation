#!/usr/bin/env python3
import sys

input = sys.stdin.readline


def Y():
    print("Yes")


def N():
    print("No")


def ST():
    return input().rstrip()


def I():
    return int(input())


def MI():
    return map(int, input().split())


def LI():
    return list(MI())


S = ST()

if ("A" not in S) or ("B" not in S):
    N()
else:
    Y()
