n=int(input())
h=list(map(int, input().split()))

cnt=0
h_max=0
for hi in h:
  if hi>=h_max:
    cnt+=1
    h_max=max(h_max, hi)
print(cnt)