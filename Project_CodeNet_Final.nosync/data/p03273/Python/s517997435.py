#!/usr/bin/env python3

def main():
    h, w = map(int, input().split())
    rows = [input() for i in range(h)]
    rows = filter(rows)
    cols = transpose(rows)
    cols = filter(cols)
    rows = transpose(cols)
    for r in rows:
        print("".join(r))

def transpose(rows):
    h = len(rows)
    w = len(rows[0])
    cols = [[rows[i][j] for i in range(h)] for j in range(w)]
    return cols

def filter(rows):
    rows = [r for r in rows if "#" in r]
    return rows

main()
