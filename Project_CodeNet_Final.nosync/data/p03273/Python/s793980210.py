import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    h, w = map(int, readline().split())
    grid = []
    hd = 0
    for row in range(h):
        s = input()
        if all([char == "." for char in s]):
            hd += 1
        else:
            grid.append(s)

    rem = []
    for col in range(w):
        for row in range(h - hd):
            if grid[row][col] == "#":
                break
        else:
            rem.append(col)

    for row in range(h-hd):
        disp = ""
        for col in range(w):
            if col in rem:
                continue
            disp += grid[row][col]
        print(disp)


if __name__ == '__main__':
    main()
