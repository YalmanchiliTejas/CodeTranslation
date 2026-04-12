N = int(input())
As = list(map(int, input().split()))

result = 0
before_sum = sum(As)
for i in range(N-1):
    before_sum-=As[i]
    result+=As[i]*(before_sum)
print(result%(1*10**9+7))
