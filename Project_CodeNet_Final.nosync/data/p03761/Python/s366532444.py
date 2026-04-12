from collections import Counter

n = int(input())
C = Counter(list(input()))

for _ in range(n-1):
  C = C & Counter(list(input()))

ans_str = ''

for k, v in sorted(C.items()):
  ans_str += k*v
  
print(ans_str)