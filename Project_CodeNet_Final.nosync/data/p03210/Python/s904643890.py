# ABC114a
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

x = int(input())
print('YNEOS'[not x in [3, 5, 7]::2])
