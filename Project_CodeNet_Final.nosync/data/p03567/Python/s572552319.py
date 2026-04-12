import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    s=input()
    if s.count('AC')>=1:
        print('Yes')
    else:
        print('No')
resolve()