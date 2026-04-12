n=int(input())
h=[int(i) for i in input().split()]
m=0;
cnt=0;
for i in range(len(h)):
    if m<=h[i]:
      cnt=cnt+1  
      m=h[i]
print(cnt)
