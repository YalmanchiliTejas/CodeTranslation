h, w = [int(x) for x in input().split()]
m = [list(input()) for _ in range(h)]

def solve():
    x, y = 0, 0
    while x != w - 1 or y != h - 1:
        m[y][x] = '.'

        if y < h - 1 and m[y + 1][x] == '#':
            if x < w - 1 and m[y][x + 1] == '#':
                return False
            else:
                if '#' in m[y]:
                    return False
                y += 1
        elif x < w - 1 and m[y][x + 1] == '#':
            for i in range(h):
                if '#' == m[i][x]:
                    return False
            x += 1
        else:
            return False

    return True

print('Possible' if solve() else 'Impossible')
