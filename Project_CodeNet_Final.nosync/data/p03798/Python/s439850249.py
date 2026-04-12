def main():
  N = int(input())
  s = input()

  # S: 1, W: 0
  for a0, a1 in ((0, 0), (0, 1), (1, 0), (1, 1)):
    l = [a0, a1]

    for c in s[1:] + s[0]:
      if c == 'o':
        a0, a1 = a1, not (a0 ^ a1)
      else:
        a0, a1 = a1, (a0 ^ a1)
      l.append(a1)

    if (l[0] == a0) and (l[1] == a1):
      print(''.join('S' if i else 'W' for i in l[:-2]))
      exit()

  print(-1)

if __name__ == '__main__':
  main()