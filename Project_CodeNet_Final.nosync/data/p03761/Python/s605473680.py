from collections import Counter
n = int(input())
alphabet = Counter(input())
for i in range(n-1):
  s = Counter(input())
  for x in alphabet:
    if alphabet[x] > s[x]:
      alphabet[x] = s[x]
print("".join(sorted(alphabet.elements())))