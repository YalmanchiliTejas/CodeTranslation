N=int(input())
H=list(map(int,input().split()))
x=int(0)
y=int(0)

for i in range(N):
    for j in range(i):
      if H[i]>=H[j]:
        y+=1
    if y>=i:
        x+=1
    y=int(0)

print(x)