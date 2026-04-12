import sys
read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    A, B, C, X, Y = map(int, readline().split())
    ans = A*X+B*Y
    if X>=Y:
        ans = min(ans, C*Y*2+A*(X-Y), C*X*2)
    else:
        ans = min(ans, C*X*2+B*(Y-X), C*Y*2)
    print(ans)

if __name__ == '__main__':
    main()
