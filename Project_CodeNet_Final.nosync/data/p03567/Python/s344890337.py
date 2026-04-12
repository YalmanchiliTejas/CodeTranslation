import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    
    s=str(input())
    ans='No'
    for i in range(len(s)-1):
        if s[i:i+2]=='AC':
            ans='Yes'
    print(ans)
    
    
resolve()