N, X = map(int, input().split())
An = [1]
Pn = [1]

for i in range(N):
  An.append(2*An[i]+3)
  Pn.append(2*Pn[i]+1)

ans = 0
#print(An, Pn)

def f(x, i):
  global ans

  if x == An[i]:
    ans += Pn[i]
    print(ans)

  elif An[i]//2 + 1 < x < An[i]:
    ans += Pn[i-1] + 1
    f(x-(An[i]//2 + 1), i-1)

  elif An[i]//2 + 1 == x:
    ans += Pn[i-1] + 1
    print(ans)

  elif 1 < x <= An[i]//2:
    f(x-1, i-1)

  else:
    print(ans)

f(X, N)