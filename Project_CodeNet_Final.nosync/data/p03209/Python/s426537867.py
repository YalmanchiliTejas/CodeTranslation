N, X = map(int, input().split())

length = [1]
paty = [1]
for i in range(N):
  length.append(3 + length[-1] * 2)
  paty.append(1 + paty[-1] * 2)

def num_paty(n, f, t):
  global length
  global paty

  if f >= length[n] or t < 0:
    ret = 0
  elif f <= 0 and t >= length[n]-1:
    ret = paty[n]
  else:
    half = length[n] // 2
    ret = 1 if f <= half and t >= half else 0
    ret += num_paty(n-1, f-1, t-1)
    ret += num_paty(n-1, f-half-1, t-half-1)
  return ret

print(num_paty(N, 0, X-1))