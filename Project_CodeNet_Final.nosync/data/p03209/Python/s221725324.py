n, x = map(int, input().split())

def bgsize(n):
  return 2 ** (n+2) - 3

def patty(n):
  return 2 ** (n+1) - 1

lv1 = 'BPPPB'
ans = 0
pos = 0
lv = n
eat = False

while True:

  if pos == x:
    break

  if eat:
    ans += 1
    pos += 1
    eat = False
    continue

  if lv ==1 and x - pos < 5:
    ans += lv1[:x-pos].count('P')
    break

  if pos + bgsize(lv) <= x:
    ans += patty(lv)
    pos += bgsize(lv)
    eat = True
  else:
    pos += 1
    lv -= 1

print(ans)