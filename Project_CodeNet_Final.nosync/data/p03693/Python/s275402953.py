import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    a,b,c=MI()
    N=b*10+c
    if N%4==0:
        print("YES")
    else:
        print("NO")

main()
