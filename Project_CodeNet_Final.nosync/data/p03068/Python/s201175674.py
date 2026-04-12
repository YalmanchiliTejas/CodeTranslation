n = int(input())
s = input()
k = int(input())

sl = list(s)
sk = sl[k-1]
for i in range(n):
  if sl[i] != sk:
    sl[i] = "*"

print("".join(sl))
