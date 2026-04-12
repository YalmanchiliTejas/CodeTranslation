N = int(input())
s = input()
def calcnext(a, b, c):
  if b == "W":
    c = "x" if c == "o" else "o"
  n = a if c == "o" else "S" if a == "W" else "W"
  return n
for ab in ["SS", "SW", "WS", "WW"]:
  l = list(ab)
  for i in range(2, N+2):
    n = calcnext(l[i-2], l[i-1], s[(i-1)%N])
    l.append(n)
  #print(l)
  if l[N:N+2] == l[0:2]:
    print("".join(l[:N]))
    exit()
print(-1)
