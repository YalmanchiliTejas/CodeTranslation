# AGC007a
def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)
    h, w = map(int, input().split())

    cou = 0
    for _ in range(h):
        cou += input().count('#')
    if cou == h+w-1:
        print('Possible')
        exit(0)
    print('Impossible')


if __name__ == '__main__':
    main()
