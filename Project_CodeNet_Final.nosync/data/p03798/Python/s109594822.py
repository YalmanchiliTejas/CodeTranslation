d ={"o":0, "x":1}
e =["S","W"]
n = int(input())
s = [d[t] for t in input()]

for i in range(4):
  a = [-1]*(n+2)
  a[0] = i%2
  a[1] = i//2
  for i in range(n):
    a[i+2] = a[i] ^ a[i+1] ^ s[i]
  if a[0] == a[n] and a[1] == a[n+1]:
    print("".join([e[t] for t in a[1:n+1]]))
    quit()
print(-1)