#!/usr/bin/env python3
# -*- coding: utf-8 -*-

RIGHT = "yuiophjklnm"


def solve(s):
    counter = 0
    prev = s[0] in RIGHT
    for c in s[1:]:
        now = c in RIGHT
        if prev != now:
            counter += 1
        prev = now
    return counter


if __name__ == "__main__":
    while True:
        s = input()
        if s == "#":
            break
        else:
            print(solve(s))