n = int(input())
s = [int(i) for i in input().split()]
ans = n

for i in range(1,n):
    temp = s[i]
    for j in range(i):
        if(s[j] > temp):
            ans -= 1
            break
        
        
print(ans)     