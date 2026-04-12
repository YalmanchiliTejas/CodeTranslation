n=int(input())
l=list(map(int, input().split()))
cnt=0
a=l[0]
for i in range(n):
  if a<=l[i]:
    cnt=cnt+1
    a=l[i]

print(cnt)