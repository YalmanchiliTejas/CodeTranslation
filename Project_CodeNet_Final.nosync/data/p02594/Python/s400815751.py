#!/usr/bin/env python3


def solve(S: str):
    if S >= 30:
        return "Yes"
    return "No"


def main():
    S = int(input())
    answer = solve(S)
    print(answer)


if __name__ == "__main__":
    main()
