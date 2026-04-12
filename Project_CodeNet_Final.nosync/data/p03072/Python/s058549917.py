N = int(input())
L = list(map(int, input().split()))

a = L.pop(0)

ans = 1
for i in L:
    if i >= a:
        ans += 1
        a = i
        
print(ans)