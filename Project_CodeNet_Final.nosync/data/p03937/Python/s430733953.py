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
def debug(x):
    print(x,file=sys.stderr)
def printglobals():
    for (symbol, value) in globals().items():
        print('symbol="%s"、value=%s' % (symbol, value),file=sys.stderr)
def printlocals():
    for (symbol, value) in locals().items():
        print('symbol="%s"、value=%s' % (symbol, value),file=sys.stderr)
#入力（後でいじる）
def pin(type=int):
    return map(type,input().split())

#繰り返し自乗法だよ
#これはnのp乗をmで割ったあまりをだすよ
def modular_w_binary_method (n,m,p):
    ans=1 if n>0 else 0
    while(p>0):
        if p%2==1:
            ans=(ans*n)%m
        n=(n**2)%m
        p//=2
    return ans
#mod上でのaの逆元を出すよ
"""
    フェルマーの小定理より a**(p)%p==a isTrue
    これを利用すれば a**(p-2)%p==a**(-1) isTrue
    元と逆元とをかけてpで割れば1が余るよ！
"""
def modular_inverse(a,prime):
    return(modular_w_binary_method(a,prime,prime-2))
#逆元を使うと容易に頑張れるｃ
def conbination(n,a,mod=10**9+7):
    #cはイラない
    res=1 
    for s in range(a):
        res=(res*(n-s)*(modular_inverse(s+1,mod)))%mod

        
    return res
#操作から作れるものの組み合わせは何個かー＞同じものでも違う方法で構成できるかから考える方法もある
"""
"""

#solution:

#input
H,W=pin()
h=0
for i in range(H):
    t=list(input())
    for j in t:
        if j=="#":
            h+=1
#print(h)
print(["Impossible","Possible"][h==(H+W-1)])
#print(m)
#print(["No","Yes"][cond])
#print([["NA","YYMM"],["MMYY","AMBIGUOUS"]][cMMYY][cYYMM])
"""
#printデバッグ消した？
#前の問題の結果見てないのに次の問題に行くの？
"""
"""
お前カッコ閉じるの忘れてるだろ
"""