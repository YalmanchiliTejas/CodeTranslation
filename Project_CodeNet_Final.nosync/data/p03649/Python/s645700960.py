# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

#k, = map(int,read().split())

def make(k):
    if k==0:
        print(1)
        print(0)
        exit()
    
    k -= 1
    n = 50
    q = k//n
    r = k%n
    
    a = [(2*n-1)+q]*n
    for i in range(r):
        for j in range(n):
            if i==j: a[j] += n
            else: a[j] -= 1
        
    print(n)
    print(*a)


def judge(n,a):
    if max(a) < n:
        return 0
    
    ans = 0
    for i in range(n):
        if a[i] > 3*n:
            d = (a[i]-3*n)//(n+1)
            ans += d
            a[i] -= d*(n+1)
    
    #print(ans)
    if ans >= 2*n:
        ans += n*ans    
    else:
        for i in range(n):
            a[i] += ans

    #print(ans,a)
    #return
    
    while True:
        if max(a) < n:
            return ans
        
        idx = max(range(n),key=lambda i:a[i])
        for j in range(n):
            a[j] += 1
        a[idx] -= n+1
        ans += 1
        #print(idx,a)


n,*a = map(int,read().split())

print(judge(n,a))




