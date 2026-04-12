# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

L, W, Z = map(int, input().split())

n = (L-Z)//(W+Z)
print(n)
