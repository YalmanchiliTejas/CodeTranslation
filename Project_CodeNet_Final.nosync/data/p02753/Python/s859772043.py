import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    S = readline().strip()
    
    if S in ('AAA', 'BBB'):
        print('No')
    else:
        print('Yes')
    
    return


if __name__ == '__main__':
    main()
