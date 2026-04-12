import sys
input = sys.stdin.buffer.readline
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))


n, m = MAP()
print('Yes') if n == m else print('No')
