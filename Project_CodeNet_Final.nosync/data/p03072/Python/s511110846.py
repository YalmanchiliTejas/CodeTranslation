n = int(input())

h = [int(i) for i in input().split()]

output = 1

for i in range(n):
  if i != 0:
    cal = h[0:i]
    if h[i]>=max(cal):
      output = output + 1

print(output)
