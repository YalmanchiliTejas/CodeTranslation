import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N,M=map(int,input().split())
    print('Yes' if N==M else 'No')

if __name__ == '__main__':
    main()
