n = int(input())
S = [input() for i in range(n)]

min_cnt = [50]*26

for i in range(n):
  word = [0]*26
  for j in range(len(S[i])):
    word[ord(S[i][j])-ord("a")] += 1
  for j in range(26):
    min_cnt[j] = min(min_cnt[j],word[j])
str = ""
for i in range(26):
  for j in range(min_cnt[i]):
    str += chr(i+ord("a"))
print(str)