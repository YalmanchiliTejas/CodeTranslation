import sys


def main():
    input = sys.stdin.buffer.readline
    a, b, c, x, y = map(int, input().split())
    ans = 0
    if 2 * c < a + b:
        m = min(x, y)
        ans += 2 * c * m
        x -= m
        y -= m
    if 2 * c < a:
        ans += 2 * c * x
        x = 0
    if 2 * c < b:
        ans += 2 * c * y
        y = 0
    ans += a * x + b * y
    print(ans)


if __name__ == "__main__":
    main()
