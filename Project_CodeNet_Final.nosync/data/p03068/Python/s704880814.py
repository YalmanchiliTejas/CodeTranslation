import re

def solve():
  N = int(input())
  S = input()
  K = int(input())
  return re.sub('[^' + S[K - 1] + ']', '*', S)

print(solve())
