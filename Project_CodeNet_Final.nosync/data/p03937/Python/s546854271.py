#!/usr/bin/env python3
import sys
INF = float("inf")


def yes():
    print("Possible")  # type: str


def no():
    print("Impossible")  # type: str


def main():
    H, W = map(int, input().split())
    A = [None]*H
    for i in range(H):
        A[i] = list(input())

    # 個数がH+W-1でなければ、条件を満たすさない。
    if H+W-1 != sum([A[i].count("#") for i in range(H)]):
        no()
        return

    # 連結しているか
    yes()

    pass


if __name__ == '__main__':
    main()
