import sys
N,M = map(int,input().split())

if not ( 1 <= N <= 100 and 0 <= M <= N ): sys.exit()
print('Yes') if N == M else print('No')