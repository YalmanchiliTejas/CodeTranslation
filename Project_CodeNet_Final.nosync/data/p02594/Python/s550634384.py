#create date: 2020-08-02 21:00

import sys
stdin = sys.stdin

def ns(): return stdin.readline().rstrip()
def ni(): return int(ns())
def na(): return list(map(int, stdin.readline().split()))

def main():
    x = ni()
    print("Yes" if x >= 30 else "No")

if __name__ == "__main__":
    main()