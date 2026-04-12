# ABC064a
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input()[:-1].replace(' ', ''))
print('YNEOS'[n % 4 != 0::2])
