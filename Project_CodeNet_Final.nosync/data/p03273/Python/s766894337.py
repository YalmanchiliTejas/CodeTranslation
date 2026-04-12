h, w = map(int, input().split())
ban = []
banban = []

for i in range(h):
  tmp = input()
  if tmp != '.'*w:
    ban.append(list(tmp))

for zlist in zip(*ban):
  if '#' in zlist:
    banban.append(zlist)

for letter in zip(*banban):
  print(''.join(letter))