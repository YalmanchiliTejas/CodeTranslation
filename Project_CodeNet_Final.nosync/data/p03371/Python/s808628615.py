import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def main():
    a, b, c, x, y =MI()
    ans = float('inf')
    for i in range(0, max(x*2, y*2)+1, 2):
        p = a*max(0, x-i//2) + b*max(0, y-i//2) + c*i
        ans = min(ans, p)
    print(ans)


if __name__ == '__main__':
    main()