n = int(input())
h = [i for i in map(int,input().split())]
ans=0
for i in range(n):
    if max(h[:i]+[0]) <=h[i]: ans+=1
print(ans)