s = int(input())
l = list(map(int,input().split()))
ans = 1
x = l[0]
for i in range(s-1):
    if l[i] <= l[i+1] and x <=l[i+1]:
        ans += 1
        x = l[i+1]
print(ans)