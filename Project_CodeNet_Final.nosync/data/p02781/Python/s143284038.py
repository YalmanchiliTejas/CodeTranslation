''' Hey stalker :) '''
INF = 10**10
def main():
    #print = out.append
    ''' Cook your dish here! '''
    n = list(input())
    k = get_int()
    ln = len(n)
    ans = 0
    def solve(nz, ind, locked = False):
        if nz == 0: return 1
        if ind>=ln: return 0
        num = int(n[ind])
        ans = 0
        for index in range(ind,ln):
            if locked and ind==index:
                if nz==1: ans += 1
                else:
                    for i in range(index+1, ln):
                        if int(n[i])>0:
                            ans += solve(nz-1, i, True)
                            break
                ans += solve(nz-1, index+1)*(num-1)
            else: ans += solve(nz-1, index+1)*9
            #print(index, ans)
        #print(nz, ind, locked, ans)
        return ans

    ans = solve(k,0, True)
    print(ans)


''' Pythonista fLite 1.1 '''
import sys
from collections import defaultdict, Counter
from bisect import bisect_left, bisect_right
#from functools import reduce
import math
#input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
out = []
get_int = lambda: int(input())
get_list = lambda: list(map(int, input().split()))
main()
#[main() for _ in range(int(input()))]
print(*out, sep='\n')
