#!/usr/bin/env python3
import sys

input = sys.stdin.readline


def Y():
    print("Yes")


def N():
    print("No")


def S():
    return input().rstrip()


def I():
    return int(input())


def MI():
    return map(int, input().split())


x = I()
if x >= 30:
    Y()
else:
    N()
