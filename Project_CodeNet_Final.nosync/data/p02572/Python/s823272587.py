import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    n = I()
    a = LI()
    tasi = sum(a)
    num = 10**9+7
    ans = 0
    
    for i in range(n):
        tasi -= a[i]
        tasi %= num
        ans += a[i]*tasi
        ans %= num

    print(ans)
main()            
