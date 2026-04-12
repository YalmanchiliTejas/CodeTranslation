# coding: utf-8


def solve(*args: str) -> str:
    n, m = map(int, args[0].split())

    return 'Yes' if n == m else 'No'


if __name__ == "__main__":
    print(solve(*(open(0).read().splitlines())))
