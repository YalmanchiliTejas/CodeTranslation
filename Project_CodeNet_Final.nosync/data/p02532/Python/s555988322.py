n = int(raw_input())
stacks = [[] for x in xrange(n)]

while True:
  line = raw_input().split(' ')
  if line[0] == 'quit':
    break

  if line[0] == 'push':
    p = int(line[1]) - 1
    q = line[2]
    stacks[p].append(q)
  elif line[0] == 'pop':
    p = int(line[1]) - 1
    print stacks[p].pop()
  elif line[0] == 'move':
    p1 = int(line[1]) - 1
    p2 = int(line[2]) - 1
    stacks[p2].append(stacks[p1].pop())