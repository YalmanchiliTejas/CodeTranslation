n = int(input())
A = [0 for i in range(26)]
s = input()
for i in range(len(s)):
  A[ord(s[i]) - 97] += 1
for j in range(1, n):
  B = [0 for i in range(26)]
  s = input()
  for i in range(len(s)):
    B[ord(s[i]) - 97] += 1
  for i in range(26):
    A[i] = min(A[i], B[i])
ans = ""
for i in range(26):
  ans += chr(97+i) * A[i]
print(ans)