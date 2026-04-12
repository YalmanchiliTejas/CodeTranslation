import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

s = input().rstrip()

if s == 'AAA' or s == 'BBB':
    print("No")
else:
    print("Yes")
