from collections import Counter
n = int(input())
S = [Counter(input()) for _ in range(n)]
ans = {}
for i in S[0].keys():
  ans[i] = min([s[i] for s in S])
  
print("".join(sorted([i*j for i, j in ans.items()])))