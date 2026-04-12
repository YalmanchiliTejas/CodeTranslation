n = int(input())
hs = list(map(int, input().split()))
 
answer = 1
for i in range(1, n):
  if max(hs[:i]) <= hs[i]:
    answer += 1
 
print(answer)