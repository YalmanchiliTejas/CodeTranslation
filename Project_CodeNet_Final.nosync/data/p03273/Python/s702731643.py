from collections import defaultdict
import itertools
import copy

def readInt():
  return int(input())
def readInts():
  return list(map(int, input().split()))
def readChar():
  return input()
def readChars():
  return input().split()

def p(arr,b="\n",e="\n"):
  print(b,end="")
  for i in arr:
    for j in i:
      print(j,end="")
    print()
  print(e,end="")

h,w = readInts()
a = [list(input()) for i in range(h)]

for i in range(h-1,-1,-1):
  boo = 1
  for j in range(w-1,-1,-1):
    if a[i][j]=="#":
      boo = 0
  if boo==1:
    del a[i]

for i in range(len(a[0])-1,-1,-1):
  boo = 1
  for j in range(len(a)-1,-1,-1):
    if a[j][i]=="#":
      boo = 0
  if boo==1:
    for j in range(len(a)-1,-1,-1):
      del a[j][i]

p(a,b="",e="")