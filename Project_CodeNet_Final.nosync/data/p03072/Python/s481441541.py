n=int(input())
h=list(map(int,input().split()))
a=[h[0]]
for i in range(1,n):
    if a[-1]<=h[i]:
        a.append(h[i])

print(len(a))