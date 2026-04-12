# -*- coding: utf-8 -*-
"""
C - Align
https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c

"""
import sys


from collections import deque

def solve(N, numbers):
    res = deque([numbers[0]])
    numbers = deque(numbers[1:])
    while numbers:
        bb = abs(numbers[-1] - res[-1])
        bf = abs(numbers[-1] - res[0])
        ff = abs(numbers[0] - res[0])
        fb = abs(numbers[0] - res[-1])
        t = sorted([[bb, 'bb'], [bf, 'bf'], [ff, 'ff'], [fb, 'fb']])
        if t[-1][1] == 'bb':
            res.append(numbers.pop())
        elif t[-1][1] == 'bf':
            res.appendleft(numbers.pop())
        elif t[-1][1] == 'ff':
            res.appendleft((numbers.popleft()))
        elif t[-1][1] == 'fb':
            res.append(numbers.popleft())

    res = list(res)
    return sum([abs(a-b) for a, b in zip(res, res[1:])])



def main(args):
    N = int(input())
    numbers = sorted([int(input()) for _ in range(N)])
    ans = solve(N, numbers)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])