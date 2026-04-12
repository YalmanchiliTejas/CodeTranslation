N = int(input())
H = list(map(int,input().split()))
highest = 0
ans = 0
for i in H:
  if highest <= i: 
    ans += 1
    highest = i
print(ans)    