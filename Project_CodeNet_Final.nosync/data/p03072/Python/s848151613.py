N = int(input())
H = list(map(int, input().split()))
highest = 0
c = 0
for h in H:
  if h >= highest:
    c+=1
    highest=h
print(c)