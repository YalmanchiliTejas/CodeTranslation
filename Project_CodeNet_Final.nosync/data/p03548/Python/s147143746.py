#!/usr/bin/env pypy3
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    x,y,z=MI()
    x-=z
    print(x//(y+z))
    
    

main()
