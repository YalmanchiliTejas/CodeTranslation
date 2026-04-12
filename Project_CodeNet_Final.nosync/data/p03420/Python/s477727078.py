l = input().split(" ")
N = int(l[0])
K = int(l[1])
ts = 0
for b in range(K + 1, N + 1):
  ts += (N // b) * (b - K) \
      + max(0, N % b - K + 1)
  if K == 0:
    ts -= 1
print(ts)
