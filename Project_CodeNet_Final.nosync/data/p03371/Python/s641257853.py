#from math import gcd

from math import factorial as f

from math import ceil,floor,sqrt


import bisect
import re
import heapq


from copy import deepcopy
import itertools

from sys import exit

ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

yes = "Yes"
no = "No"

def main():
    a,b,c,x,y = mi()
    ans = 1<<60
    for i in range(max(x,y)+1):
        ans = min(max(x-i,0)*a+max(y-i,0)*b+2*i*c,ans)
    print(ans)


main()


