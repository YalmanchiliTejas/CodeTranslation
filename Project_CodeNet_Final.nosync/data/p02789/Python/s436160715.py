import sys
def ISI(): return map(int, sys.stdin.readline().rstrip().split())

n, m=ISI()
if(n==m):print("Yes")
else:print("No")