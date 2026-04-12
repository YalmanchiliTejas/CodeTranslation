from collections import Counter
N = int(input())
S = [Counter(input()) for _ in range(N)]
comS = {}
for key in S[0].keys():
  if all([True for s in S if key in s]):
    comS[key] = min([s[key] for s in S])
print(''.join([key*comS[key] for key in sorted(comS.keys())]))