N = int(input())
S = [input() for _ in range(N)]
dic = {}
X = sorted(list(set(S[0])))
for i in X:
  dic[i] = 51
for i in range(N):
  for x in X:
    dic[x] = min(dic[x],S[i].count(x))
for i in X:
  print(i * dic[i],end="")