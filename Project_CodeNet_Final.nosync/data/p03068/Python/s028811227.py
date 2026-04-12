N = int(input())
S = input()
K = int(input())
list = []
Sk = S[K-1]
for i in range(0,N):
  s = S[i]
  s_ans = Sk if s == Sk else "*"
  list.append(s_ans)
ans = "".join(list)
print(ans)
