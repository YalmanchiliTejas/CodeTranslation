def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return list(input())
n=I()
H=IL()
m=0
c=0
for i in range(n):
  if H[i]>=m:
    c+=1
  m=max(m,H[i])
print(c)