H, W = map(int, input().split())
arr = []

for _ in range(H):
  s = input()
  if '#' in s:
    arr.append(s)

j = 0
while len(arr[0]) > j:
  if '#' not in [arr[i][j] for i in range(len(arr))]:
    for i in range(len(arr)):
      arr[i] = arr[i][:j] + arr[i][(j+1):]
  else:
    j += 1

for s in arr:
  print(s)