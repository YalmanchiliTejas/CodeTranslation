N= int(input())
A =list(map(int,input().rstrip().split(" ")))
ma = 0
ans = 0
for i in A:
    if i >= ma:
        ans += 1
        ma = i
print(ans)