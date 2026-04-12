import sys
from copy import copy
input = sys.stdin.readline
'''
n, m = map(int, input().split())
n = int(input())
A = list(map(int, input().split()))
S = input().strip()
for test in range(int(input())):
'''
inf = 100000000000000000  # 1e17
mod = 998244353

S = input().strip()
for i in range(1,len(S)):
    if S[i]!=S[i-1]:
        print("Yes")
        sys.exit()
print("No")
