n=int(input())
h=list(map(int,input().split()))
c=1
for i in range(1,n):
    c += h[i]==max(h[:i+1])
print(c)