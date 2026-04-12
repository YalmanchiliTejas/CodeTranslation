import sys
input = sys.stdin.readline

H, W = map(int, input().split())
arr = [[j for j in input().rstrip()] for i in range(H)]
b = [x for x in arr if '#' in x]
c = zip(*[x for x in zip(*b) if '#' in x])
for x in c:
  print("".join(x))