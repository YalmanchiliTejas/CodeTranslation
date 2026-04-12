N=int(input())
H=list(map(int,input().split()))
hold=0
count=0
for i in range(N):
  if H[i]>=hold:
    hold=H[i]
    count+=1
print(count)