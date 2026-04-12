def resolve():
  h, w = map(int, input().split())
  a = []
  for i in range(h):
    s = input()
    if '#' in s:
      a.append(s)
  h = len(a)
  blk_clm = set()  # '#' を含む列
  for i in range(h):
    for j in range(w):
      if a[i][j] == '#':
        blk_clm.add(j)

  for i in range(h):
    for j in range(w):
      if j in blk_clm:
        print(a[i][j], end='')
    print('')

  return

if __name__ == "__main__":
  resolve()
