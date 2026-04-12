N = int(input())
s = input()
s += s[0]

def main():
  # S: 1, W: 0
  for a0, a1 in ((0, 0), (0, 1), (1, 0), (1, 1)):
    l = [a0, a1]

    for c in s[1:]:
      if c == 'o':
        a0, a1 = a1, not (a0 ^ a1)
      else:
        a0, a1 = a1, (a0 ^ a1)
      l.append(a1)

    if (l[0] == l[-2]) and (l[1] == l[-1]):
      print(''.join('S' if i == 1 else 'W' for i in l[:-2]))
      exit()

  print(-1)

if __name__ == '__main__':
  main()