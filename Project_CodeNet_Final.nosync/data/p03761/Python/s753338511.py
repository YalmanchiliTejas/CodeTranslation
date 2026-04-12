import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n = f()[0]
    cnt = [2500] * 26
    for i in range(n):
        s = input()
        cnts = [0] * 26
        for c in s:
            cnts[ord(c)- ord('a')] += 1
        
        for j in range(26):
            cnt[j] = min(cnt[j], cnts[j])
    
    for i in range(26):
        if cnt[i]>0:
            for j in range(cnt[i]):
                print(chr(ord('a')+i), end='')
    
    print()

solve()
