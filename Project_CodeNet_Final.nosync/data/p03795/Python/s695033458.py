import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N = int(readline())
    x = 800*N
    y = N//15*200
    print(x-y)


if __name__ == '__main__':
    main()
