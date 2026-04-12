import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n = f()[0]
    print(n*800 - n//15 * 200)

solve()
