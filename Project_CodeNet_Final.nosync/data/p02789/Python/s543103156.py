def read_ints(row):
    return list(map(int, row().split()))
  
import sys
 
row =sys.stdin.readline
N,M = read_ints(row)
print("Yes" if N == M else "No")