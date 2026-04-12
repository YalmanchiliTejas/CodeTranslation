N = int(input())
H = list(map(int, input().split()))
cnt = 0
pre = 0
for x in H:
   if pre <= x:
      cnt+=1
      pre = x
print(cnt)