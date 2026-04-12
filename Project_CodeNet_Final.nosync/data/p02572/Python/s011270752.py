import sys
from math import sqrt, gcd, ceil, log, floor
from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))

MOD = 10**9 + 7
def main():
	n = int(input()); arr = read()
	pref = [i for i in arr]
	for i in range(1, n):pref[i] += pref[i-1]
	ans = 0
	for i in range(n):
		ans += (arr[i] * (pref[-1]-pref[i]))%MOD
		ans %= MOD
	print(ans)



if __name__ == "__main__":
	main()
