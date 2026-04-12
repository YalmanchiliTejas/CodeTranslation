import sys
def I(): return int(sys.stdin.readline())
def LI(): return [int(x) for x in sys.stdin.readline().split()]

def main():
    N,M = LI()
    if N==M:
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    main()
