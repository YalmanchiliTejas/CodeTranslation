number = list(map(str, input().split(" ")))
N = "".join(number)
if int(N) % 4 == 0:
  print("YES")
else:
  print("NO")
