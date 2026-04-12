#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
    R, G, B = map(int, input().split())
    print('YES'if int(str(R) + str(G) + str(B)) % 4 == 0 else 'NO')


if __name__ == "__main__":
    main()
