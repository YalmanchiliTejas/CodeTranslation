n=int(input())
h=map(int,input().split())
H=list(h)
s=1
d=H[0]
for i in range(1,n):
    if H[i]>=d:
        s=s+1
        d=H[i]
    else:
        continue

print(s)
