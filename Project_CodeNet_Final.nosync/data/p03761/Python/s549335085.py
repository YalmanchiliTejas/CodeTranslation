# -*- coding: utf-8 -*-
from string import ascii_lowercase


def list_n():
    return [int(e) for e in input().split()]


def list_s():
    return [s for e in input().split()]


def main(n, ss):
    answer = ''
    for c in ascii_lowercase:
        answer += c * min([s.count(c) for s in ss])
    return answer


if __name__ == '__main__':
    n = int(input())
    ss = [input() for _ in range(n)]
    print(main(n, ss))
