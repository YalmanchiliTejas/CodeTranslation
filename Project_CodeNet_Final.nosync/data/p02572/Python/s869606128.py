n = int(input())
lis = list(map(int, input().split()))

s = sum(lis) ** 2
ss = sum([i ** 2 for i in lis])

print(((s - ss)//2)%(10**9+7))
    
    