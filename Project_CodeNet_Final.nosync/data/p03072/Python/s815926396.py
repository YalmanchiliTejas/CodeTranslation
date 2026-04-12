N = int(input())
H = [int(_) for _ in input().split()]
Hlist = list(map(lambda x:x-H[0],H))
result = 1
compareValue = Hlist[0]
for i in range(N-1):
  if Hlist[i+1] >= compareValue:
    result += 1
    compareValue = Hlist[i+1]
print(result)