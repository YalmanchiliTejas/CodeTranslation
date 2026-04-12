import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    print(800*n-(n//15)*200)
resolve()