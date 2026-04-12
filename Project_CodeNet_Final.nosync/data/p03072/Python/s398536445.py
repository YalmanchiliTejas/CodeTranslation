n=int(input())
h=[int(i) for i in input().split()]
max=0
cnt=0
for i in range(n):
    if max<=h[i]:
        cnt+=1
        max=h[i]
print(cnt)