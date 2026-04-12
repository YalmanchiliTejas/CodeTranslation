n = int(input())
h = list(map(int, input().split(" ")))
result = 1

for i in range(n):
  viewable = False
  for j in range(i):
    if h[j] > h[i]:
      break
    elif j == i - 1:
      viewable = True
      
  if viewable == True:
    result += 1

print("{}".format(result))