# ABC078b
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

x, y, z = map(int, input().split())
print((x-z)//(y+z))