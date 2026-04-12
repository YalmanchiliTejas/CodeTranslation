import sys
from io import StringIO
import unittest

doTest=0

def yn(n):
    if n==1:
        print("Yes")
    else:
        print("No")
    return

def resolve():
    readline=sys.stdin.readline

    #n,m,k=list(map(int, readline().strip().split()))
    #arr=list(map(int, readline().strip().split()))
    s=readline().strip()

    if s[0]==s[1] and s[0]==s[2]:
        yn(0)
    else:
        yn(1)
    #yn(n)

    return

if doTest==0:
    resolve()
    sys.exit()