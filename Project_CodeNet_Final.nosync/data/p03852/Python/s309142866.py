import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    s = input()
    if s in ['a', 'e', 'i', 'o', 'u']:
        print('vowel')
    else:
        print('consonant')

solve()
