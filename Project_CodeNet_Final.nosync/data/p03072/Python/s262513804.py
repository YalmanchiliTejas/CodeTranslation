n = input()
list_h = raw_input().split()
h = [int(s) for s in list_h]
count = 1
max_h = h[0]

for i in range(1, n):
 if h[i] >= h[i-1] and h[i] >= max_h:
  count += 1
  max_h = h[i]
print count