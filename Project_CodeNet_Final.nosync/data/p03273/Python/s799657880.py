#!/usr/bin/env python3

def main():
    na = list(map(int, input().split()))
    H, W = na[0], na[1]

    a = []
    for i in range(H):
        s = input()
        if '#' in s:
            a.append(s)

    b = [0] * W
    for s in a:
        for i in range(W):
            if s[i] == '#':
                b[i] = 1

    for s in a:
        ss = ''
        for i in range(W):
            if b[i] == 1:
                ss += s[i]
        print(ss)


if __name__ == '__main__':
    main()

