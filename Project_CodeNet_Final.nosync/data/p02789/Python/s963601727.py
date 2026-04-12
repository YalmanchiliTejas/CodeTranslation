import sys
input=sys.stdin.readline
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

n,m=MAP()

if n==m:
    print("Yes")

else:
    print("No")

