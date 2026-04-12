i = list(map(int, input().split()))
j = 100 * i[0] + 10 * i[1] + i[2]
if j % 4 == 0:
  print("YES")
else:
  print("NO")