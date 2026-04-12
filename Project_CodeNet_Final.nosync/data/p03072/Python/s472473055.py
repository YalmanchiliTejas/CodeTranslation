n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(n):
    b = a[:i+1]
    c = sorted(b,reverse=True)
    if c[0]==b[i]:
        ans +=1
print(ans)