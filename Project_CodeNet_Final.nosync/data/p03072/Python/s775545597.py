a = int(input())
l = list(map(int,input().split()))
max = 0
ans = 0
for i in l:
    if max <=i:
        max =i
        ans =ans+1
print(ans)