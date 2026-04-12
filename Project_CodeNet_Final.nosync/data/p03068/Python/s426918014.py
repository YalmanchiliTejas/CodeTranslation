N = int(input())
S = str(input())
K = int(input())

swap_word = S[K-1]

ans = []
for i in range(N):
  if S[i] != swap_word:
    ans.append("*")
  else:
    ans.append(S[i])

ans_word = ""
for i in range(N):
  ans_word = ans_word + ans[i]

print(ans_word)
