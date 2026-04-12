# !/usr/bin/python3


def solve(n):
    if n >= 30: return "Yes"
    return "No"


if __name__ == "__main__":
    n = int(input())

    print(solve(n))
