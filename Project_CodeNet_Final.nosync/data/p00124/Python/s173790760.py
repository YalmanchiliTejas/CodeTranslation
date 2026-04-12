# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0124
"""
import sys
from operator import itemgetter


def solve(data):
    result = []
    for name, win, lose, draw in data:
        score = win * 3 + draw * 1
        result.append([name, score])
    result.sort(key=itemgetter(1), reverse=True)
    return result


def main(args):
    first_data_set = True
    while True:
        n = int(input())
        if n == 0:
            break
        data = []
        for _ in range(n):
            name, win, lose, draw = input().split()
            data.append([name, int(win), int(lose), int(draw)])
        result = solve(data)
        
        if first_data_set:
            first_data_set = False
        else:
            print()
        for r in result:
            print(','.join(map(str, r)))


if __name__ == '__main__':
    main(sys.argv[1:])