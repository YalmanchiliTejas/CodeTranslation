N = int(input())
AList = list(map(int, input().split()))

mod = 10 ** 9 + 7
sumnumber = sum(AList)

result = 0
for i in AList:
    result += (sumnumber - i) * i
    
    sumnumber -= i

print(result % mod)