#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve(inp):
    S = inp.readline().strip()

    if S[0] == S[1] == S[2]:
        return "No"
    else:
        return "Yes"


def main():
    import sys
    result = solve(sys.stdin)
    if result is not None and result != '':
        print(result)


if __name__ == '__main__':
    main()
