N=int(input())
H=list(map(int,input().split()))

cnt=0
highest=H[0]

for i in range(N):
  if highest<=H[i]:
    cnt+=1
    highest=H[i]

print(cnt)
