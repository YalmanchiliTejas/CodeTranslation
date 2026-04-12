import sys
from io import StringIO
import unittest

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline

    #n,m,k=list(map(int, readline().strip().split()))
    #arr=list(map(int, readline().strip().split()))
    #n=int(readline().strip())
    s=input()
    print("vowel" if s in ["a","i","u","e","o"] else "consonant" )

    return

if 'doTest' not in globals():
    resolve()
    sys.exit()

### ----------------
### ここまでコピぺえ 
### ----------------