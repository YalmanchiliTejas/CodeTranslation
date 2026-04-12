#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

input = sys.stdin.readline

def main():
    N = int(input())
    print(800 * N - 200 * int(N / 15))

main()
