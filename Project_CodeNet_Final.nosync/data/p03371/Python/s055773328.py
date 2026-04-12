#!/usr/bin/env python3
def main():
    A, B, C, X, Y = map(int, input().split())

    all_double = 2 * max(X, Y) * C
    double = 2 * Y * C + (X - Y) * A if X >= Y else 2 * X * C + (Y - X) * B
    single = X * A + Y * B
    print(min(all_double, double, single))


if __name__ == '__main__':
    main()
