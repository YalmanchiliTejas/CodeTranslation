#!/usr/bin/env python3
# -*- coding: utf-8 -*-



def main():
    X, Y, Z = map(int, input().split())

    ans = (X-Z) // (Y+Z)
    print(ans)

if __name__ == "__main__": main()
