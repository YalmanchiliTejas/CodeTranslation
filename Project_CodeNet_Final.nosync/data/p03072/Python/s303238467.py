n = int(input())
h = list(map(int, input().split()))
ans=1
for i in range(1,n):
    h_h = sorted(h[:i+1])
    if h[i]==h_h[i]:
        ans+=1
print(ans)