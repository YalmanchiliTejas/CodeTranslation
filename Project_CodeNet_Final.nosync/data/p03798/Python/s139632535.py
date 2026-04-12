import sys
N, = map(int, raw_input().split())
s  = raw_input()
for i in ["SS", "SW", "WS", "WW"]:
  r = [None] * (N+2)
  r[0:2] = list(i)
  for j in range(2, N+2):
    r[j] = "S" if bool(r[j-2]=="S") ^ bool(r[j-1]=="S") ^ bool(s[(j-1)%N]=="o") else "W"
  if r[N:N+2]==list(i):
    print "".join(r[:N])
    sys.exit(0)
print -1