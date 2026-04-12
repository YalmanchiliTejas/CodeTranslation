N = int(input())
S = [input() for _ in range(N)]

char_lst = [chr(i) for i in range(97,97+26)]

solver = []
for i in range(len(char_lst)):
  var = 100
  for j in range(N):
    var = min(var, S[j].count(char_lst[i]))
  solver.extend([char_lst[i]]*var)
solver.sort()
ans = ''.join(solver)
print(ans)