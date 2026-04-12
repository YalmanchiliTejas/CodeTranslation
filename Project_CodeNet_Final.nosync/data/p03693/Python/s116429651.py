import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    r, g, b = map(int, readline().split())
    N = r * 100 + g * 10 + b
    if N % 4 == 0:
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()
