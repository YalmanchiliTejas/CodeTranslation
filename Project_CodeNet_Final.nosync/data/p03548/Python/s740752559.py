#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
    X, Y, Z = map(int, input().split())
    print(int((X - Z) / (Y + Z)))


if __name__ == "__main__":
    main()
