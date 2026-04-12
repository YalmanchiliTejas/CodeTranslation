#!/usr/bin/env python3


def main():
    H, W = [int(x) for x in input().split()]
    a = [input() for _ in range(H)]
    a = [ai for ai in a if "#" in ai]
    ar = zip(*[bi for bi in zip(*a) if "#" in bi])
    for ai in ar:
        print("".join(ai))


if __name__ == '__main__':
    main()
