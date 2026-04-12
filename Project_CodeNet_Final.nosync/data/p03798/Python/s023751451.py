N = int(input())
s = input()
s += s[0]

# S: 1, W: 0
for a0, a1 in ((0, 0), (0, 1), (1, 0), (1, 1)):
  l = [a0, a1]

  for i in range(1, N + 1):
    if s[i] == 'o': l.append(not (l[i] ^ l[i - 1]))
    else: l.append(l[i] ^ l[i - 1])

  if (l[0] == l[-2]) and (l[1] == l[-1]):
    s = ''.join(['S' if i == 1 else 'W' for i in l[:-2]])
    print(s)
    exit()

print(-1)