n = int(input())
strings = [input() for _ in range(n)]

candidate_char = [100] * 26 # alphabet

for string in strings:
  string_char = [0] * 26
  for char in string:
    string_char[ord(char) - ord('a')] += 1
  
  for i in range(26):
    candidate_char[i] = min(candidate_char[i], string_char[i])

# print(candidate_char)
for i, char_num in enumerate(candidate_char):
  for j in range(char_num):
    print(chr(ord('a') + i), end="")