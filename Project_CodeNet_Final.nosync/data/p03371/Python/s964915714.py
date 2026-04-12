#!/usr/bin/env python
# coding: utf-8
"""
purpose
"""


def main() -> None:
    """
    main function
    """
    (A, B, C, X, Y) = map(int, input().split())

    if 2 * C <= A + B:
        ans = C * min(X, Y) * 2 + min(max((X-Y)*A, (Y-X)*B), max(X-Y, Y-X)*C*2)
    else:
        ans = A * X + B * Y

    print(ans)


if __name__ == "__main__":
    main()
