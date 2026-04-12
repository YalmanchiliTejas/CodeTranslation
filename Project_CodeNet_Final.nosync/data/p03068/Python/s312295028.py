n = int(input())
word = input()
k = int(input())

letter = word[k - 1]
replaced = ""

for w in word:
  if w == letter:
    replaced += letter
  else:
    replaced += "*"

print(replaced)