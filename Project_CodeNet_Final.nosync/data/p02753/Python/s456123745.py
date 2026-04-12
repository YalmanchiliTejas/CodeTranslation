import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
read = sys.stdin.read

#h,w,k = [int(i) for i in read().split()]

if len(set(i for i in input()))==2:
    print("Yes")
else:
    print("No")

