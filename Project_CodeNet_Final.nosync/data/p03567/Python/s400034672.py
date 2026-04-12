
import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    s=input()
    ans='No'
    for i in range(len(s)-1):
        if s[i]=='A' and s[i+1]=='C':
            ans='Yes'
    print(ans)
resolve()