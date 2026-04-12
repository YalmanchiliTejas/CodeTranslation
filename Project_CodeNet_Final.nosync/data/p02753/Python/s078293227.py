import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    s=input()
    if s=='AAA' or s=='BBB':
        print('No')
    else:
        print('Yes')
resolve()