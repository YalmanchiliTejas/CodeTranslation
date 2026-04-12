li = list(map(int, input().split()))

if (li[0]*100 + li[1]*10 + li[2]) % 4 == 0:
  print("YES")
else:
  print("NO")

