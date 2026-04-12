X, Y, Z=list(map(int, input().split()))
a=[]
for i in range(10**5):
  if X>=i*(Y+Z)+Z:
    a.append(i)
print(a[-1])