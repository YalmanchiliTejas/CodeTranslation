n = int(input())
S = [input() for _ in range(n)]

from collections import Counter

answer=''
memo=[Counter(s) for s in S]
for c in 'abcdefghijklmnopqrstuvwxyz':
  answer += c * min([counter[c] for counter in memo])

print(answer)