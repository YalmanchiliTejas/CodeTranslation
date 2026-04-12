N = int(input())
H = [int(x) for x in input().split()]

SUM = 1
for i in range(1,len(H)):
  if sum([h > H[i] for h in H[:i]]) == 0 :
    SUM += 1
print(SUM)