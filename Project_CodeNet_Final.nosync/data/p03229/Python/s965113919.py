N = int(input())
As = []
for i in range(N):
  A = int(input())
  As.append(A)
As.sort()
if N%2 == 0:
  r = 2*sum(As[N//2+1:])-2*sum(As[:N//2-1])+As[N//2]-As[N//2-1]
if N%2 == 1:
  r1 = 2*sum(As[N//2+1:])-2*sum(As[:N//2-1])-As[N//2]-As[N//2-1]
  As.reverse()
  r2 = -2*sum(As[N//2+1:])+2*sum(As[:N//2-1])+As[N//2]+As[N//2-1]
  r = max(r1, r2)
print(r)
