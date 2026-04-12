h,w = map(int,input().split())

hc = 0
a=[]
for _ in [0]*h:
  x = list(input())
  if "#" in x:
    a += [x]
    hc += 1

wc = 0
b=[]
for i in range(w):
  x = [a[k][i] for k in range(hc)]
  if "#" in x:
    b += [x]
    wc += 1

for i in range(hc):
  print("".join([b[k][i] for k in range(wc)]))
