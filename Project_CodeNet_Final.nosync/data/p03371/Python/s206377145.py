import sys

def main():
  input = sys.stdin.readline
  A, B, C, X, Y = map(int, input().split())
  n = max(X, Y)
  ans = float('INF')
  for i in range(max(X, Y)+1):
    cur = C * 2 * i + max(0, X - i) * A + max(0, Y - i) * B
    ans = min(ans, cur)
  print(ans)


if __name__ == '__main__':
  main()