import sys
input = sys.stdin.readline

s = input().strip()

def cond():
    if s == 'AAA' or s == 'BBB':
        return False
    else:
        return True

if cond():
    print('Yes')
else:
    print('No')
