n = input()
h = input()
h = h.split(" ")
h = [int(x) for x in h]
max = 0
counter = 0
for _, i in enumerate(h):
  if i >= max:
    counter += 1
    max = i
print(counter)