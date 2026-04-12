h,w = map(int,input().split())
a = [input() for i in range(h)]


count = 0
for i in range(h-1,-1,-1):
  if "#" not in a[i]:
    del a[i]
    count +=1
h -=count

tenti_a = list(map(list, zip(*a)))
count = 0
for i in range(w-1,-1,-1):
  if "#" not in tenti_a[i]:
    del tenti_a[i]
    count +=1
w -=count

tenti_tenti_a = list(map(list, zip(*tenti_a)))
for i in range(h):
  print(str(tenti_tenti_a[i]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))