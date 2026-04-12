import sys
INF = 10**10
MOD = 10**9 + 7
sys.setrecursionlimit(100000000)
from functools import lru_cache
from copy import deepcopy 

def main():
    n = int(input())
    s = input()
    flag = False  
    
    for bit in range(4):
        ani0 = (bit>>0)&1
        ani1 = (bit>>1)&1

        if ani0 == 0:
            ans = ['S']
        else:
            ans = ['W']

        if ani1 == 0:
            ans.append('S')
        else:
            ans.append('W')
        
        before2 = ani0
        before1 = ani1
        for i in range(n - 1):
            if s[i + 1] == 'o':
                tmp = before2^before1
            else:
                tmp = before2^before1^1
            
            before1,before2 = tmp,before1

            if i != n - 2:
                if before1:
                    ans.append('W')
                else:
                    ans.append('S')
        
        if s[0] == 'o':
            tmp = before2^before1
        else:
            tmp = before2^before1^1
        
        before1,before2 = tmp,before1

        if before1 == ani1 and before2 == ani0:
            flag = True
            break
    
    if flag:
        print(''.join(ans))
    else:
        print(-1)

if __name__=='__main__':
    main() 