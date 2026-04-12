hpi = input()
count = 1
k = list(map(int, input().split(" ")))
for c in range(int(hpi) - 1):
  jo = "yes"
  n = k[:c + 2]
  for co in range(len(n) - 1):
    if n[co] > k[c + 1]:
      jo = "no"
    else:
      pass
  if jo == "yes":
    count += 1
print(count)
