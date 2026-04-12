# -*- coding: utf-8 -*-

from sys import stdin

def main():
    _ = stdin.readline().rstrip()
    s = stdin.readline().rstrip()
    k = int(stdin.readline())

    target = s[k-1]
    ans = ''

    for c in s:
        if c == target:
            ans += c
        else:
            ans += '*'
    print(ans)

if __name__=='__main__':
    main()