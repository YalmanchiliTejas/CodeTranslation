import sys
input = sys.stdin.readline

N = int(input())
S = input()
K = int(input())

target = S[K-1]
res = ''
for i in range(N):
  if S[i] != target:
    res += '*'
  else:
    res += target
print(res)
