### ----------------
### ここから
### ----------------

import sys
from io import StringIO
import unittest

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline

    #n,m,k=map(int, readline().rstrip().split())
    #arr=list(map(int, readline().rstrip().split()))
    n=int(readline())
    if n>=30:
        print("Yes")
    else:
        print("No")
    #ss=readline().rstrip()
    #yn(1)

    return

if 'doTest' not in globals():
    resolve()
    sys.exit()

### ----------------
### ここまで 
### ----------------