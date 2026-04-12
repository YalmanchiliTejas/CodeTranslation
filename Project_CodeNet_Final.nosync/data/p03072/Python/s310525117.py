#!/usr/bin/env python3

def main():
    N = int(input())
    Hs = [int(s) for s in input().split()]
    result = 0
    for i, ryokan in enumerate(Hs):
        for i2, syougai in enumerate(Hs):
            if i2 == i:
                result += 1
                break
            if ryokan < syougai:
                break
    print(result)


if __name__ == "__main__":
    main()
