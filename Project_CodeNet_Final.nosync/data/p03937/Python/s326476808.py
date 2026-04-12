#!/usr/bin/env python3


def main():
    h, w = (int(x) for x in input().split())
    passed = sum(input().count("#") for _ in range(h))
    if passed == h + w - 1:
        print("Possible")
    else:
        print("Impossible")


if __name__ == '__main__':
    main()
