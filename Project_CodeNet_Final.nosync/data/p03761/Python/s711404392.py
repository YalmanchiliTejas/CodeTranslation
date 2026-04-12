n = int(input())
A = [[0] * n for i in range(26)]
S = ""

for i in range(n):
  for j in input():
    A[ord(j)-97][i] += 1

for i in range(26):
  S += chr(i+97) * min(A[i])
  
print(S)