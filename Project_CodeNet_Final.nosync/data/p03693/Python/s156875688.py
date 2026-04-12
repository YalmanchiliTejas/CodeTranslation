import sys
import math
import bisect

def main():
    r, g, b = map(int, input().split())
    val = r * 100 + g * 10 + b
    if val % 4 == 0:
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()
