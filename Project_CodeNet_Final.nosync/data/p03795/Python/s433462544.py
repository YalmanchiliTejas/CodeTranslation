import sys

def solve():
    N = int(input())
    ans = 800 * N - 200 * (N // 15)
    print(ans)
    
def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None


if __name__ == '__main__':
    solve()