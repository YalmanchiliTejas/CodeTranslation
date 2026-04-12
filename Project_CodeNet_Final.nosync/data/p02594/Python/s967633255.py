# coding: utf-8


def solve(*args: str) -> str:
    x = int(args[0])

    return 'Yes' if 30 <= x else 'No'


if __name__ == "__main__":
    print(solve(*(open(0).read().splitlines())))
