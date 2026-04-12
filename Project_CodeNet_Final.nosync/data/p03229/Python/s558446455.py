n = int(input())
a = [int(input()) for _ in range(n)]
# print(a)
a.sort()
n2 = n//2
if n % 2 == 0:
    print(sum(a[n2:])*2 - sum(a[:n2])*2 - a[n2]+a[n2-1])
else:
    
    ans1 = sum(a[n2+1:])*2 - sum(a[:n2+1])*2 + a[n2-1]+a[n2]
    
    ans2 = sum(a[n2:])*2 - sum(a[:n2])*2 - a[n2]-a[n2+1]
    print(max(ans1, ans2))
