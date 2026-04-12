n = int(input())
if n ==1:
    print(0)
    exit()
a = [int(input()) for _ in range(n)]
a.sort()
na = [0]*n
c = n//2
if n%2 == 1:
    if a[c]-a[c-1] < a[c+1]-a[c]:
        lst1 = a[:c+1]
        lst2 = a[c+1:]
        na[0] = lst1[-1]
        na[-1] = lst1[-2]
    else:
        lst1 = a[c:][::-1]
        lst2 = a[:c]
        na[0] = lst1[-1]
        na[-1] = lst1[-2]
else:
    lst1 = a[:c]
    lst2 = a[c:][::-1]
    na[0] = lst1[-1]
    na[-1] = lst2[-1]
i1 = i2 = 0
for i in range(1,n-1):
    if i%2 == 0:
        na[i] = lst1[i1]
        i1 += 1
    else:
        na[i] = lst2[i2]
        i2 += 1
# print(na)
ans = 0
for i in range(1,n): ans += abs(na[i]-na[i-1])
print(ans)