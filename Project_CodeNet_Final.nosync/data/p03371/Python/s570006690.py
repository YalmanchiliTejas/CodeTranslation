def input():
    import sys
    return sys.stdin.readline().rstrip()


def main():
    import math
    import collections
    import itertools

    a, b, c, x, y = map(int, input().split())
    if a + b < 2 * c:
        print(a * x + b * y)
    else:
        # num_c = min(x, y)
        if x < y:
            if b < 2 * c:
                print(x * 2 * c + (y - x) * b)
            else:
                print(y * 2 * c)
        else:
            if a < 2 * c:
                print(y * 2 * c + (x - y) * a)
            else:
                print(x * 2 * c)
        
        



if __name__ == '__main__':
    main()