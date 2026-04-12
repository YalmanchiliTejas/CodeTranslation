input()
count = 0
B = []
A = list(map(int,input().split()))
for i in A:
  B.append(i)
  if max(B) <= i:
    count += 1
  else:
    pass
print(count)