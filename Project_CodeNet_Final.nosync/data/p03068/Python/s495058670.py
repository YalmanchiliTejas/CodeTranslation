N = int(input())
S = input()
K = int(input())-1
ans = ""
for i in S:
  if i!=S[K]:
    ans+="*"
  else:
    ans+=S[K]
print(ans)