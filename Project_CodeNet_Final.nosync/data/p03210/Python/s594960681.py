import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))

def main():
    x = II()
    if x==3 or x==5 or x==7: print('YES')
    else: print('NO')

if __name__ == '__main__':
    main()
