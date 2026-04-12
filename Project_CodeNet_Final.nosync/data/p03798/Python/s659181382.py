N = int(input())
s = input()
s += s[0]
l = [0] * (N + 2)

# S: 1, W: 0
for a0, a1 in ((0, 0), (0, 1), (1, 0), (1, 1)):
  l[0], l[1] = a0, a1

  for i in range(1, N + 1):
    if s[i] == 'o': l[i + 1] = not (l[i] ^ l[i - 1])
    else: l[i + 1] = l[i] ^ l[i - 1]

  if (l[0] == l[-2]) and (l[1] == l[-1]):
    print(*['S' if i == 1 else 'W' for i in l[:-2]], sep='')
    exit()

print(-1)