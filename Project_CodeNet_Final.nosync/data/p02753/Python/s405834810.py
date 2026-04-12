import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LMI(): return list(map(int, sys.stdin.readline().split()))
MOD = 10 ** 9 + 7

S = input()
print('Yes' if S.count('A') > 0 and S.count('B') > 0 else 'No')
