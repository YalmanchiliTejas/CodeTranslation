N = int(input())
H = [int(i) for i in input().split()]
top = H[0]
ct = 0
for i in H:
  if top <= i:
    ct += 1
    top = i
print(ct)