###template###
import sys
def input(): return sys.stdin.readline().rstrip()
def mi(): return map(int, input().split())
###template###

X, Y, Z = mi()

#Y+2Zで1人座れる
#そこからY+Z増えるごとに1人ずつ座れる量が増えていく

yz = X - (Y+ 2*Z)
print(1+yz//(Y+Z))




