#!/usr/bin/env python3

def main():
    n = int(input())
    S = input()
    k = int(input())
    print(*[s if s == S[k - 1] else "*" for s in S], sep="")


if __name__ == "__main__":
    main()
