import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
def resolve():
    S = sr()
    if S == 'AAA' or S == 'BBB':
        print('No')
    else:
        print('Yes')
resolve()