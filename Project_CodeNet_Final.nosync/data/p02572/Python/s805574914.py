import copy
n = int(input())
a = list(map(int,input().split()))
a_2 = copy.copy(a)
a_2.reverse()
sinu = [0] * n
t = 0
for i in range(n):
    t += a_2[i]
    sinu[i] += t
sinu.reverse()

ans = 0
for i in range(n-1):
    #print(a[i],sinu[i+1])
    ans += a[i] * sinu[i+1]

    
print(ans%(10**9+7))
