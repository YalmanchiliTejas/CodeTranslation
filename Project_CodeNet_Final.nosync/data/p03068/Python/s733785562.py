N = int(input())
S = input()
K = int(input())
ans = ""
for i in S:
  if i != S[K - 1]: ans += "*"
  else: ans += S[K - 1]  
print(ans)  