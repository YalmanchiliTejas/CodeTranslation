import sys
import math
import bisect

def main():
    n = int(input())
    ans = n * 800
    ans -= n // 15 * 200
    print(ans)

if __name__ == "__main__":
    main()
