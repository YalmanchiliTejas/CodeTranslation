import sys
def input():
    return sys.stdin.readline()[:-1]
n,m=map(int,input().split())
if n==m:
    print("Yes")
else:
    print("No")