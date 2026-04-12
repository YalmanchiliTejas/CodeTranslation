#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################
n = int(input())
arr = list(map(int , input().split()))
psum = [0]*n
psum[0] = arr[0]
m = 10**9 + 7
for i in range(1,n):
	psum[i] = (psum[i-1] + arr[i])%(m)
ans = 0
for i in range(n-1):
	#print(arr[i],(psum[n-1] - psum[i]))
	ans += arr[i]*(psum[n-1] - psum[i])
	ans = ans % m
print(ans)








