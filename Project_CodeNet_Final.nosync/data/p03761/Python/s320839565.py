n = int(input())
words = []
for i in range(n):
  words.append(input())
for i in words:
  i = "".join(sorted(i))
words = sorted(words)
word = ""
for i in words[0]:
  if i not in word:
    word+=i
result = ""
for i in word:
  minim = 51
  for j in words:
    if j.count(i)<minim:
      minim = j.count(i)
  result+=i*minim
result = "".join(sorted(result))
print(result)