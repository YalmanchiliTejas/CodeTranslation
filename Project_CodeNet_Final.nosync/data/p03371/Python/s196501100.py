sum = 0
A,B,C,X,Y = map(int,input().split())
AB = C*2
ans = float("inf")

for i in range(10**5+1):
    sum = AB*i + A*max(0,X-i) + B*max(0,Y-i)
    if sum < ans:
        ans = sum

print(ans)
