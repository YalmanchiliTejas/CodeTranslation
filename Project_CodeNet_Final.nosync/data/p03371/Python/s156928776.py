import sys
import time
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    A,B,C,X,Y = map(int, readline().split())
    Z = min(X, Y)
    if A + B >= C * 2:
        ans = min(C * Z * 2 + A * (X - Z) + B * (Y - Z), C * max(X, Y) * 2)
    else:
        ans = A * X + B * Y
    print(ans)

if __name__ == '__main__':
    main()