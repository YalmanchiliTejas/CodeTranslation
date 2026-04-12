import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N=int(input())
    print('YES' if N==5 or N==7 or N==3 else 'NO')

if __name__ == '__main__':
    main()
