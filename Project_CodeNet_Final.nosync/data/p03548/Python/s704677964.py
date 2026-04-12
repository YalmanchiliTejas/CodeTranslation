isu, hito, sukima =  map(int, input().split())

ninzuu = 0
while True:
  ans = isu // ((hito + sukima) * ninzuu + sukima)
  if ans == 0:
    break
  ninzuu = ninzuu + 1
print(ninzuu-1)