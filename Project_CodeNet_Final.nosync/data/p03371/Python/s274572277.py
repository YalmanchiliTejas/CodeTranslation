#!/usr/bin/env python
# coding: utf-8
#

def main(a, b, c, x, y):

    # min(a * A + b * B + c * C)
    # A + C/2 >= x
    # B + C/2 >= y
    m = []
    # 全部AとB
    m.append(a * x + b * y)
    # 全部C
    m.append(c * max(x, y) * 2)
    # xの方が多くて途中からA
    if x >= y: m.append(c * min(x, y) * 2 + a * (x - y))
    if x < y: m.append(c * min(x, y) * 2 + b * (y - x))
    print(min(m))
    


if __name__ == '__main__':
    try:
        a, b, c, x, y = list(map(int, input().strip().split(' ')))
        main(a, b, c, x, y)
    except EOFError:
        pass
