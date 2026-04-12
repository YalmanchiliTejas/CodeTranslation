H, W = map(int, input().split())
a = [input() for _ in range(H)]
#print(a)

def compress(b, h, w):
  b = [c for c in b if '#' in c]
  b = [''.join(x) for x in zip(*b)]
  b = [c for c in b if '#' in c]
  b = [''.join(x) for x in zip(*b)]
  if len(b) == h and len(b[0]) == w:
    return b
  return compress(b, len(b), len(b[0]))

r = compress(a, H, W)
for i in range(len(r)):
  print(r[i])
