#!/usr/bin/env python3

YES = "Possible"  # type: str
NO = "Impossible"  # type: str


def main():
    h, w = map(int, input().split())
    c = sum([input().count("#") for _ in range(h)])
    print("Possible" if h + w - 1 == c else "Impossible")

if __name__ == '__main__':
    main()
