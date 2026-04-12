N = int(input())
Hs= list(map(int, input().split()))
r = 1
n = Hs[0]
for h in Hs[1::]:
  if h >= n:
    r +=1
    n = h
print(r)