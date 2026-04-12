N = int(input())
input = [int(s) for s in input().split()]
ans = 0
temp=sum(input)
for i in range(N-1):
    temp=temp-input[i]
    ans = (ans + (input[i]*((temp)%(10**9+7)))%(10**9+7))%(10**9+7)
print(ans)