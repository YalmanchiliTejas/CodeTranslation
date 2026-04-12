import sys

def main():
    input = sys.stdin.readline
    x, y, z = map(int, input().split())

    print((x - z) // (y + z))


if __name__ == '__main__':
    main()
