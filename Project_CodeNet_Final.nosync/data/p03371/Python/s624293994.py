import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))
MIIZ = lambda: list(map(lambda x: x-1, MII()))

def main():
    a, b, c, x, y = MII()
    fee = min(a+b,c*2) * min(x,y)
    if x > y: fee += min(a,c*2)*(x-y)
    else: fee += min(b,c*2)*(y-x)
    print(fee)


if __name__ == '__main__':
    main()
