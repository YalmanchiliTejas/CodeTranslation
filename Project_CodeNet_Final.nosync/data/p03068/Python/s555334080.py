n, s, k = [input() for i in range(3)]
target = s[int(k)-1]
s = list(s)
for i in range(int(n)):
  if s[i] != target:
    s[i] = '*'
print("".join(s))