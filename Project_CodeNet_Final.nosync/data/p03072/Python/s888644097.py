A = int(input())
l =[int(i) for i in input().split()]
ans = 0
 
for t in range(1,A+1):
    tt = int(t)
    if l[tt-1] == max(l[:tt]):
        ans += 1
    
print(ans)