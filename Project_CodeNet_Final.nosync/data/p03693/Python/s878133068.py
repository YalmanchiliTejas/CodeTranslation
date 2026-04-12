#!/usr/bin/env python3
# -*- coding: utf-8 -*-



def main():
    A, B, C = map(int, input().split())

    N = 100*A + 10*B + C
    ok = N % 4 == 0
    print("YES" if ok else "NO")

if __name__ == "__main__": main()
