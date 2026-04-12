from array import array
from itertools import repeat
from operator import itemgetter


def main():
    height, width = map(int, input().split())

    grid = []
    for _ in repeat(None, height):
        grid.append(array('B', (int(c == '.') for c in input())))

    for index in range(height - 1, -1, -1):
        if all(grid[index]):
            del grid[index]

    for index in range(width - 1, -1, -1):
        if all(map(itemgetter(index), grid)):
            for row in grid:
                del row[index]

    for row in grid:
        print(''.join('.' if b else '#' for b in row))


if __name__ == '__main__':
    main()
