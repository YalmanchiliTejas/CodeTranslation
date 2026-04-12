N = int(input())
H = list(map(int,input().split()))
count,ans = 0,0
for i in H:
    if count <= i:
        count = i
        ans = ans + 1
print(ans)