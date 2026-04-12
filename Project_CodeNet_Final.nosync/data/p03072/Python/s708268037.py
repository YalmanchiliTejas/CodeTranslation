N=int(input())
c=0
H = list(map(int,input().split()))
big=H[0]
for i in range(N):
  if H[i]>=big:
    c=c+1
    if H[i]>big:
      big=H[i]
print(c)