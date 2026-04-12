N = int(input())
S = input()
K = int(input())

text = ""
for i in range(len(S)):
  if S[i] == S[K-1]:
    text += S[i]
  else:
    text += "*"

print(text)
