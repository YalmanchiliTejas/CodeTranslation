N=int(input())
H=list(map(int,input().split()))

MAX=H[0]
count=1
for i in range(1,N):
  if H[i]>=MAX:
    count += 1
    MAX = H[i]
print(count)