import sys
from itertools import accumulate
def input(): return sys.stdin.readline().strip()


def main():
    x, y, z = map(int,input().split())
    print((x - z) // (y + z))
    


if __name__ == "__main__":
    main()
