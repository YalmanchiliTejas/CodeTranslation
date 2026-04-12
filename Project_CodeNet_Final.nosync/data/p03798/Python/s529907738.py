#import numpy as np
#from numpy import*
#from scipy.sparse.csgraph import shortest_path #shortest_path(csgraph=graph) # dijkstra# floyd_warshall
#from scipy.sparse import csr_matrix
 
from collections import* #defaultdict Counter deque appendleft
from fractions import gcd
from functools import* #reduce
from itertools import* #permutations("AB",repeat=2) combinations("AB",2) product("AB",2) groupby accumulate
from operator import mul,itemgetter
from bisect import* #bisect_left bisect_right
from heapq import* #heapify heappop heappushpop
from math import factorial,pi
from copy import deepcopy
import sys
sys.setrecursionlimit(10**8)
#input=sys.stdin.readline  #危険！基本オフにしろ！
 
def main():
    n=int(input())
    s=input()
    
    #print(s)
    doubutu1=["W","W"]
    doubutu2=["S","W"]
    doubutu3=["W","S"]
    doubutu4=["S","S"]
    def doubutuappender(doubutu):
        for i in range(1,n):
            if doubutu[i]=="S":
                doubutu.append( ["SW"["S"==doubutu[i-1]] ,doubutu[i-1]][s[i]=="o"])
            else:
                doubutu.append( [doubutu[i-1] ,"SW"["S"==doubutu[i-1]]][s[i]=="o"])
        return doubutu
    for i in [doubutuappender(doubutu1),doubutuappender(doubutu2),doubutuappender(doubutu3),doubutuappender(doubutu4)]:
        if i[0]==i[-1]:
            if s[0]=="o" and i[0]=="S" and i[1]==i[-2]:
                print("".join(i[:-1]))
                exit()
            elif s[0]=="x" and i[0]=="S" and i[1]!=i[-2]:
                print("".join(i[:-1]))
                exit()
            elif s[0]=="o" and i[0]=="W" and i[1]!=i[-2]:
                print("".join(i[:-1]))
                exit()
            elif s[0]=="x" and i[0]=="W" and i[1]==i[-2]:
                print("".join(i[:-1]))
                exit()
    print(-1)
if __name__ == '__main__':
    main()