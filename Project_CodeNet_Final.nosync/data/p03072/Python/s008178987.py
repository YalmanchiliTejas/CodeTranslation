n=int(input())
h=list(map(int,input().split()))
i=0
for j in range(n):
    if h[j]>=max(h[:j+1]):
        i=i+1
print(i)