import sys
import math
import bisect

def solve(x, y, z):
    max_val = 0
    for i in range(10 ** 18):
        if y * i + z * (i + 1) <= x:
            max_val = i
        else:
            break
    return max_val

def main():
    x, y, z = map(int, input().split())
    print(solve(x, y, z))
 
if __name__ == "__main__":
    main()
