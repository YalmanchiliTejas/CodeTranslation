n = int(input())
h = list(map(int, input().split()))
h_max = 0
cnt=0
for H in h:
  if H>=h_max:
      h_max = H
      cnt+=1
print(cnt)