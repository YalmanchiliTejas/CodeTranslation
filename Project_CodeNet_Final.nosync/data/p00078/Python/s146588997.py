#!/usr/bin/env python
# coding: utf-8


def table_to_string(table):
    lines = []
    for row in table:
        line = ""
        for num in row:
            line += "% 4d" % num
        lines.append(line)
    return "\n".join(lines)


def get_answer(n):
    table = [[0 for i in xrange(n)] for j in xrange(n)]
    x = (n - 1) / 2
    y = (n - 1) / 2 + 1
    for i in xrange(1, n * n + 1):
        while 1:
            if x == n:
                x = 0
            elif x == -1:
                x = n - 1
            if y == n:
                y = 0
            if table[y][x]:
                x -= 1
                y += 1
                continue
            else:
                break
        table[y][x] = i
        x += 1
        y += 1
    return table_to_string(table)


def main():
    params = []
    while 1:
        param = int(raw_input())
        if not param:
            break
        params.append(param)

    for param in params:
        print get_answer(param)

if __name__ == '__main__':
    main()