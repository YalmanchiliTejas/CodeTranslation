n = input()
H = list(map(int, input().split()))

result = 0
diff = -1

for h in H:
  if diff <= h:
    result += 1
    diff = h
print(result)