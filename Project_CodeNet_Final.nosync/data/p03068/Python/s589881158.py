N = int(input())
s = input()
k = int(input())
s_k = s[k-1]
for i in range(N):
  if s[i] != s_k:
    s = s[:i] + '*' + s[i+1:]
print(s)