import sys
input = lambda : sys.stdin.readline().rstrip()

M = (10**9)+7
n = int(input())
As = map(int, input().split(" "))

cumsum = []
cur = 0
out = 0
for i in range(n-1):
    cur += As[i]
    out += cur*As[i+1] 
    out = out % M
print(out)