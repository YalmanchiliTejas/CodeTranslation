def root(lista, S, G, M, N, memory):
  if(S == G and memory == set(range(1, N+ 1))):
    return 1
  elif(S == G and memory != set(range(1, N+ 1))):
    return 0
  elif(lista == []):
    return 0
  else:
    roots = 0
    possibilities = 0
    possibleroots = []
    for i in range(M):
      if(S in lista[i]):
        q = list(filter(lambda x: x != S, lista[i])).pop()
        if(q in memory):
          continue
        else:
          possibleroots.append(q)
    if(possibleroots == []):
      return 0
    else:
      for q in possibleroots:
        newlista = list(filter(lambda x: x != {S, q}, lista))
        newmemory = memory| {q}
        
        roots+= root(newlista, q, G, M- 1, N, newmemory)
      return roots


N, M = map(int, input().split())
lista = []
for i in range(M):
  lista.append(set(map(int, input().split())))
  
ans = 0
for i in range(2, N+ 1):
  ans+= root(lista, 1, i, M, N, {1})
  
print(ans)