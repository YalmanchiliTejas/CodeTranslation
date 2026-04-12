n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()

a1 = []
a2 = []
a1.append(a[n//2])
a2.append(a[n//2])

for i in range((n-1)//2):
    a1.append(a[i])
    a1.append(a[n-i-1])
    
    a2.append(a[n-i-1])
    a2.append(a[i])
if not n%2:
    a1.append(a[n//2-1])
    a2.append(a[n//2-1])

ans1 = 0
ans2 = 0
for i in range(len(a1)-1):
    ans1 += abs(a1[i+1] -a1[i])
    ans2 += abs(a2[i+1]-a2[i])
print(max(ans1,ans2))