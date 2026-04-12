import sys
# input = sys.stdin.readline
from itertools import accumulate

def readlines(h, w):
    for _ in range(h):
        row = input()
        if not all(cell == "." for cell in row):
            yield row

def main():
    h, w = map(int, input().split())
    grid = list(readlines(h, w))

    columns = set()
    for i in range(w):
        if all(row[i]=="." for row in grid):
            columns.add(i)
    
    for i in range(len(grid)):
        for j in range(w):
            if j not in columns:
                print(grid[i][j], end="")
        print()


main()