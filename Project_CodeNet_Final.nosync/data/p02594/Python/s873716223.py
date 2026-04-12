import sys

def input(): return sys.stdin.readline().rstrip("\r\n")
def List(): return list(map(int, input().split()))
def Num(): return int(input())


x = Num()
print('Yes' if x >= 30 else 'No')