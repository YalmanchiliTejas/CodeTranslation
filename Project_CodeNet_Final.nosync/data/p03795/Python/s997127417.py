import sys
pagos=0
lines = sys.stdin.readlines()
for linea in lines:
    c = linea.split()
    c = list(map(int,c))
list(c)
p = c[0]
x = c[0]*800
for k in range(1,(p+1)):
  if k%15 ==0:
    pagos+=200
total = x-pagos
print(total)   