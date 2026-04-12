x = input()
m = [int(i) for i in input().split()]
compare = m[0]
count = 1
for i in range(1, int(x)):
  if m[i] >= compare:
    count += 1
    compare = m[i]
print(count)
