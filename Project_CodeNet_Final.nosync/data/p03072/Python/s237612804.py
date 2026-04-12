n=int(input())
H=list(map(int, input().split()))
h=0
t=0
for i in range(len(H)):
  if h<=H[i]:
    h=H[i]
    t+=1
print(t)