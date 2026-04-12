import sys
def input():return sys.stdin.readline()[:-1]
def N(): return int(input())
def NM():return map(int,input().split())
def L():return list(NM())
n=N()
if n>=30:
    print("Yes")
else:
    print("No")