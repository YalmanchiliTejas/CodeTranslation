N = int(input())
H = input().split()
H = [int(x) for x in H]

c = 0
for i in range(N):
  h = H[i]
  T = "Y"
  for j in range(i):
    if h < H[j]:
      T = "N"
  if T == "Y":
    c +=1
print(c)