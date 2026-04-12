import sys
sys.setrecursionlimit(10**7)

def input(): return sys.stdin.readline()[:-1]
mod = 10**9 + 7
def readInt():return int(input())
def readIntList():return list(map(int,input().split()))
def readStringList():return list(input())
def readStringListWithSpace():return list(input().split())
def readString():return input()

x = readInt()
print("Yes" if x >= 30 else "No")