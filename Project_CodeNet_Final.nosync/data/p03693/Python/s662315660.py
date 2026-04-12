import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    n=int(''.join(input().split()))
    if n%4 == 0:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
