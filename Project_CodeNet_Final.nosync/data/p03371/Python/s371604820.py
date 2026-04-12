import math
from math import gcd
INF = float("inf")

import sys
input=sys.stdin.readline
import itertools

def main():
    a,b,c,x,y = map(int, input().split())
    num = max(x,y)
    ans = INF
    for i in range(0,num*2+1,2): # cをi枚買うとする
        half = i//2
        c_cst = i*c
        a_cst = max(x-half,0)*a
        b_cst = max(y-half,0)*b
        ans = min(ans,(c_cst+a_cst+b_cst))
    print(ans)



if __name__=="__main__":
    main()
