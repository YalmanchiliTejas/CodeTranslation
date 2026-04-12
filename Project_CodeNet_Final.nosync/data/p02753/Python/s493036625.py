S = list(input())
ans ="No"
for i in range(3):
  if S[i] != S[(i+1)%3]:
    ans = "Yes"
print(ans)