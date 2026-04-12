import math
import string

def intinput():
    return int(input())

def listintinput():
    return list(map(int,input().split()))

def splitintinput():
    return map(int,input().split())

X, Y, Z = splitintinput()
print(int((X-Z)/(Y+Z)))
