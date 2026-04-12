import sys
readline = sys.stdin.readline

N,X,M = map(int,readline().split())
MAXD = 55

# nex[t][v] = v (mod M)から2 ** tステップ進んだ先の値
# まずnex[0][v] は、v (mod M)から1ステップ進んだ先の値を入れておく
# sums[t][v] = v (mod M)から2 ** tステップ進んだ総和
# まずsums[0][v]は、各項がvそのものになる（1ステップだから）

nex = [[-1] * M for i in range(MAXD + 1)]
sums = [[0] * M for i in range(MAXD + 1)]

# まず、1ステップ進んだ先の値を入れる
for r in range(M):
  nex[0][r] = r * r % M
  sums[0][r] = r

for p in range(MAXD):
  for r in range(M):
    nex[p + 1][r] = nex[p][nex[p][r]]
    sums[p + 1][r] = sums[p][r] + sums[p][nex[p][r]]
    # 最初は、1ステップ（今いる場所）の場合の総和が入っている。次の進み先の総和と足すことで、
    # 今いる場所と次の場所の総和となり、2つ進んだ場合の総和が求められる
    # これで2つ進んだ場合の総和を求めるリストになるため、
    # ここで同じことをやることで、「2つ分の総和とその次の2つ分の総和」->「4つ分の総和」となる
    
res = 0
cur = X
for p in range(MAXD, -1, -1):
  if N & (1 << p):
    res += sums[p][cur]
    cur = nex[p][cur]
    
print(res)