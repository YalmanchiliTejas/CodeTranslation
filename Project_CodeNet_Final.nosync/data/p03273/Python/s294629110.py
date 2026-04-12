from sys import stdin


def main():
    H, W = [int(x) for x in stdin.readline().rstrip().split()]
    mtx = [list(stdin.readline().rstrip()) for _ in range(H)]
    mtx = [x for x in mtx if len([y for y in x if y == '#']) != 0]
    mtx = [x for x in zip(*mtx)]
    mtx = [x for x in mtx if len([y for y in x if y == '#']) != 0]
    mtx = [x for x in zip(*mtx)]
    for x in mtx:
        print(''.join(x))


if __name__ == '__main__':
    main()
