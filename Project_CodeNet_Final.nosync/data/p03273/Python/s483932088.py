H, W = map(int, input().split())
a = [input() for _ in range(H)]
count = 0
while True:
  length = len(a)
  a = [i for i in a if not(len(set(i)) == 1 and i[0] == '.')]
  if len(a) == length:
    break
  a = list(zip(*a))
  count += 1
if count % 2 != 0: a = list(zip(*a))
[print(''.join(i)) for i in list(a)]