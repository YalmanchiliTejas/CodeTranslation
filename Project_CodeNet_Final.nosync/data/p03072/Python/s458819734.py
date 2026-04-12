n=int(input())

h=[int(x) for x in input().split()]
cnt=1
for i in range(1,n):
    if h[i]>=max(h[:i]):
        cnt+=1
print(cnt)
