#!/usr/bin/env python3

def main():
    *S, = map(str, open(0).read().split())
    S = S[0]
    if (S == "AAA" or S == "BBB"):
        print("No")
    else:
        print("Yes")


main()