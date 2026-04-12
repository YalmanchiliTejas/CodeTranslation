#!/usr/bin/env python3


def main():
    n = int(input())
    h = map(int, input().split())
    current_max = 0
    ans = 0
    for hi in h:
        if hi >= current_max:
            ans += 1
        if hi > current_max:
            current_max = hi
    print(ans)


if __name__ == '__main__':
    main()
