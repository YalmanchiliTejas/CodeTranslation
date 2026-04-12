def main():
 h, w = map(int, input().split())
 a = [input() for _ in range(h)]
 na = []
 l = [0] * (w + 1)
 for i in range(h):
  if not("#" in a[i]):
   pass
  else:
   na += [a[i]]
   for j in range(w):
    if a[i][j] == "#":
     l[j] += 1
 for i in na:
  for j in range(w):
   if l[j] != 0:
    print(i[j], end="")
  print("")
main()