N = int(input())

H = map(int, input().split())
H = list(H)

max = H[0]
counter = 0

for i in H:
  if i >= max:
    max = i
    counter += 1

print(counter)
  