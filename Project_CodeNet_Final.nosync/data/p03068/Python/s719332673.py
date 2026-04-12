N = int(input())
S = input()
K = int(input())

char = S[K-1]
string = []
for i in S:
  if (i == char):
    string.append(i)
  else:
    string.append("*")
result = ''.join(string)
print(result)