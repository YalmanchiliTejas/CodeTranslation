N=int(input())
H=[int(i) for i in input().split()]
h = 0
ans = 0
for i in H:
    if i>=h:
        ans += 1
        h = i
print(ans)
