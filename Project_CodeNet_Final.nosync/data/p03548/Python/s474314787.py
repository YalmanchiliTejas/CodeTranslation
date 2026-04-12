import sys
input = sys.stdin.readline

x,y,z=list(map(int,input().split()))

print((x-z)//(y+z))