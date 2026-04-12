n = int(input())
slis = list(input())
k = int(input())
let = slis[k-1]
for i in range(n):
  if slis[i] != let:
    slis[i] = "*"
print("".join(slis))