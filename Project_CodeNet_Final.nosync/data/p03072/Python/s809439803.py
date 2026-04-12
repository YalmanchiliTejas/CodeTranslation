N = int(input())
H = list(map(int, input().split()))
count = 0
judge = True
for i in reversed(range(1, len(H))):
  judge = True
  for j in reversed(range(i)):
    if H[i] < H[j]:
      judge = False
  if judge:
    count += 1
print(count+1)