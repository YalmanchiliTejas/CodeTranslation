# coding: utf-8
# Your code here!
# coding: utf-8
from fractions import gcd 
from functools import reduce
import sys
sys.setrecursionlimit(200000000)
from inspect import currentframe


# my functions here!
#標準エラー出力
def printargs2err(*args):
    names = {id(v):k for k,v in currentframe().f_back.f_locals.items()}
    print(', '.join(names.get(id(arg),'???')+' : '+repr(arg) for arg in args),file=sys.stderr)
def debug(*args):
    print(*args,file=sys.stderr)

def printglobals():
    for (symbol, value) in globals().items():
        print('symbol="%s"、value=%s' % (symbol, value),file=sys.stderr)
def printlocals():
    for (symbol, value) in locals().items():
        print('symbol="%s"、value=%s' % (symbol, value),file=sys.stderr)
#入力（後でいじる）
def pin(type=int):
    return map(type,input().split())
     
#input

def resolve2():
    N,A,B=pin()
    ans=0
    cycle=A+B
    ans+=A*(N//cycle)
    t=N%cycle
    if t <= A:
        ans+=t
    else:
        ans+=A
    print(ans)
def resolve():
    N=input()
    cond= N=="AAA" or N=="BBB"
    print(["No","Yes"][1-cond])
    #print(N//cycle)
    #print(ans)
    #print([["NA","YYMM"],["MMYY","AMBIGUOUS"]][cMMYY][cYYMM])
#if __name__=="__main__":resolve()

"""
#printデバッグ消した？
#前の問題の結果見てないのに次の問題に行くの？
"""
"""
お前カッコ閉じるの忘れてるだろ
"""
import sys
from io import StringIO
import unittest

class TestClass(unittest.TestCase):
    def assertIO(self, input, output):
        stdout, stdin = sys.stdout, sys.stdin
        sys.stdout, sys.stdin = StringIO(), StringIO(input)
        resolve()
        sys.stdout.seek(0)
        out = sys.stdout.read()[:-1]
        sys.stdout, sys.stdin = stdout, stdin
        self.assertEqual(out, output)
    def test_入力例_1(self):
        input = """ABA"""
        output = """Yes"""
        self.assertIO(input, output)
    def test_入力例_2(self):
        input = """BBA"""
        output = """Yes"""
        self.assertIO(input, output)
    def test_入力例_3(self):
        input = """BBB"""
        output = """No"""
        self.assertIO(input, output)

if __name__=="__main__":resolve()