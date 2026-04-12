N, X, M = map(int, input().split())

mods = [0 for i in range(M)]
vals = []
for i in range(1, M+2):
  if i == 1:
    p = X
  else:
    p = p**2 % M
  
  if mods[p] > 0:
    break
  else:
    mods[p] = i
    vals.append(p)
    if i == N:
      print(sum(vals))
      exit()

len_loop = i - mods[p]
sum_answer = sum(vals)
N_res = N - len(vals)
sum_answer += sum(vals[mods[p]-1:]) * (N_res // len_loop)
N_res = N_res % len_loop
sum_answer += sum(vals[mods[p]-1:mods[p]-1+N_res])

print(sum_answer)
  


    