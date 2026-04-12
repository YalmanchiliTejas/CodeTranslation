N = int(input())

nlist = list(map(int, input().split()))
tsum = sum(nlist)

result = 0
for i in nlist:
    tsum -= i
    result += i*tsum
    result %= (10**9+7)

print(result)
