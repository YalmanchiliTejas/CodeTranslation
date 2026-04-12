N,T,E = map(int, input().split())
x = [int(X) for X in input().split()]
a = -1
for i in range(T-E,T+E+1):
   for j in range(N):
      if i%x[j] == 0:
         a = j+1
print(a)
